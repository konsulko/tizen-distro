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

    mkdir -p ${D}${systemd_unitdir}/system/multi-user.target.wants
    ln -sf ../systemd-udev-settle.service ${D}${systemd_unitdir}/system/multi-user.target.wants/systemd-udev-settle.service
}

pkg_preinst_${PN}() {
    #!/bin/sh -e

    # setup display manager service
    mkdir -p $D${systemd_unitdir}/system/graphical.target.wants/
    ln -sf ../display-manager.path  $D${systemd_unitdir}/system/graphical.target.wants/

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

FILES_${PN} += "/lib/systemd/system/multi-user.target.wants"
FILES_${PN} += "/lib/systemd/system/multi-user.target.wants/systemd-udev-settle.service"

FILES_${PN}-dbg += "/usr/lib/weston/.debug"
