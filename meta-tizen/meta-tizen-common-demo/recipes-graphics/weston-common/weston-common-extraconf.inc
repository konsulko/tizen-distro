FILESEXTRAPATHS_append := "${THISDIR}/weston-common"

SRC_URI += "file://0001-Yocto-correct-paths-to-ln-and-chmod.patch"
SRC_URI += "file://0002-Add-a-script-to-export-UID.patch"

DEPENDS += "config-tizen-common"
RDEPENDS_${PN} += "config-tizen-common"

inherit useradd

USERADD_PACKAGES = "${PN}"
GROUPADD_PARAM_${PN} += "--system  display;"
GROUPADD_PARAM_${PN} += "--system  input;"
GROUPADD_PARAM_${PN} += "--system  weston-launch"

do_install_append() {
    install -m 755 uid.sh ${D}/etc/profile.d

    mkdir -p ${D}${prefix}/lib/systemd/user/default.target.requires
    ln -sf ../weston-user.service ${D}${prefix}/lib/systemd/user/default.target.requires/weston-user.service

    mkdir -p ${D}/lib/systemd/system/graphical.target.wants
    ln -sf ../user-session-launch@.service ${D}/lib/systemd/system/graphical.target.wants/user-session-launch@seat0-5001.service
    ln -sf ../user-session-launch@.service ${D}/lib/systemd/system/graphical.target.wants/user-session-launch@seat0-5002.service
    ln -sf ../user-session-launch@.service ${D}/lib/systemd/system/graphical.target.wants/user-session-launch@seat0-5003.service
    ln -sf ../user-session-launch@.service ${D}/lib/systemd/system/graphical.target.wants/user-session-launch@seat0-9999.service

    mkdir -p ${D}${systemd_unitdir}/system/multi-user.target.wants
    ln -sf ../systemd-udev-settle.service ${D}${systemd_unitdir}/system/multi-user.target.wants/systemd-udev-settle.service
}

pkg_preinst_${PN}() {
    #!/bin/sh -e

    # setup display manager service
    mkdir -p $D${systemd_unitdir}/system/graphical.target.wants/
    ln -sf ../display-manager.path  $D${systemd_unitdir}/system/graphical.target.wants/
    # setup display manager access (inside user session)
    mkdir -p $D${prefix}/lib/systemd/user/default.target.requires/
    ln -sf ../weston-user.service  $D${prefix}/lib/systemd/user/default.target.requires/

}

pkg_postinst_${PN} () {
    for user in alice bob carol guest; do
        for appdir in desktop manifest dbspace; do
            mkdir -p $D/home/$user/.applications/$appdir
        done
        find $D/home/$user/ -type d -exec chsmack -a User {} \;
        chown -R $user:users $D/home/$user/
    done
    
    SERVICE_PATH=$D/lib/systemd/system/user-session-launch@.service
    grep -q display-manager.path $SERVICE_PATH || sed -i 's@systemd-logind.service@systemd-logind.service display-manager.path@g' $SERVICE_PATH
}

weston-common_files += "${prefix}/lib/systemd/user/default.target.requires/weston-user.service/*"
weston-common_files += "/home/*"

FILES_${PN} += "/lib/systemd/system/graphical.target.wants/user-session-launch@seat0-5001.service"
FILES_${PN} += "/lib/systemd/system/graphical.target.wants/user-session-launch@seat0-5002.service"
FILES_${PN} += "/lib/systemd/system/graphical.target.wants/user-session-launch@seat0-5003.service"
FILES_${PN} += "/lib/systemd/system/graphical.target.wants/user-session-launch@seat0-9999.service"
FILES_${PN} += "/lib/systemd/system/graphical.target.wants/user-session@5001.service"
FILES_${PN} += "/lib/systemd/system/graphical.target.wants/user-session@5002.service"
FILES_${PN} += "/lib/systemd/system/graphical.target.wants/user-session@5003.service"
FILES_${PN} += "/lib/systemd/system/graphical.target.wants/user-session@9999.service"
