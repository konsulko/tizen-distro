FILESEXTRAPATHS_append := "${THISDIR}/weston-common"

SRC_URI += "file://0001-Yocto-correct-paths-to-ln-and-chmod.patch"
SRC_URI += "file://0002-Add-a-script-to-export-UID.patch"
SRC_URI += "file://0003-Automatically-restart-display-manager.patch"
SRC_URI += "file://0004-Modifications-for-yocto-build.patch"

DEPENDS += "config-tizen-common"
RDEPENDS_${PN} += "config-tizen-common"

inherit useradd

USERADD_PACKAGES = "${PN}"
GROUPADD_PARAM_${PN} += "--system -o display;"
GROUPADD_PARAM_${PN} += "--system -o input;"
GROUPADD_PARAM_${PN} += "--system -o weston-launch"

do_install_append() {
    install -m 755 uid.sh ${D}/etc/profile.d

    mkdir -p ${D}/lib/systemd/user/default.target.wants
    ln -sf ../weston-user.service ${D}/lib/systemd/user/default.target.wants/weston-user.service

    mkdir -p ${D}/lib/systemd/system/multi-user.target.wants
    ln -sf ../user-session-launch@.service ${D}/lib/systemd/system/multi-user.target.wants/user-session-launch@seat0-5001.service
    ln -sf ../user-session-launch@.service ${D}/lib/systemd/system/multi-user.target.wants/user-session-launch@seat0-5002.service
    ln -sf ../user-session-launch@.service ${D}/lib/systemd/system/multi-user.target.wants/user-session-launch@seat0-5003.service
    ln -sf ../user-session-launch@.service ${D}/lib/systemd/system/multi-user.target.wants/user-session-launch@seat0-9999.service
    ln -sf ../user-session@.service ${D}/lib/systemd/system/multi-user.target.wants/user-session@5001.service
    ln -sf ../user-session@.service ${D}/lib/systemd/system/multi-user.target.wants/user-session@5002.service
    ln -sf ../user-session@.service ${D}/lib/systemd/system/multi-user.target.wants/user-session@5003.service
    ln -sf ../user-session@.service ${D}/lib/systemd/system/multi-user.target.wants/user-session@9999.service
}

pkg_preinst_${PN}() {
    #!/bin/sh -e

    # setup display manager service
    mkdir -p /lib/systemd/system/graphical.target.wants/
    ln -sf ../display-manager.path  /lib/systemd/system/graphical.target.wants/
    # setup display manager access (inside user session)
    mkdir -p /lib/systemd/user/default.target.requires/
    ln -sf ../weston-user.service  /lib/systemd/user/default.target.requires/
}

pkg_postinst_${PN} () {
    for user in alice bob carol guest; do
        for appdir in desktop manifest dbspace; do
            mkdir -p $D/home/$user/.applications/$appdir
        done
        find $D/home/$user/ -type d -exec chsmack -a User {} \;
        chown -R $user:users $D/home/$user/
    done
}

weston-common_files += "/lib/systemd/user/default.target.wants/weston-user.service"
weston-common_files += "/home/*"

FILES_${PN} += "/lib/systemd/system/multi-user.target.wants/user-session-launch@seat0-5001.service"
FILES_${PN} += "/lib/systemd/system/multi-user.target.wants/user-session-launch@seat0-5002.service"
FILES_${PN} += "/lib/systemd/system/multi-user.target.wants/user-session-launch@seat0-5003.service"
FILES_${PN} += "/lib/systemd/system/multi-user.target.wants/user-session-launch@seat0-9999.service"
FILES_${PN} += "/lib/systemd/system/multi-user.target.wants/user-session@5001.service"
FILES_${PN} += "/lib/systemd/system/multi-user.target.wants/user-session@5002.service"
FILES_${PN} += "/lib/systemd/system/multi-user.target.wants/user-session@5003.service"
FILES_${PN} += "/lib/systemd/system/multi-user.target.wants/user-session@9999.service"
