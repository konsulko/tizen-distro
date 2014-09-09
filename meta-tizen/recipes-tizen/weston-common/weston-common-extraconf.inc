FILESEXTRAPATHS_append := "${THISDIR}/weston-common"

SRC_URI += "file://0001-Yocto-correct-paths-to-ln-and-chmod.patch"
SRC_URI += "file://0002-Add-a-script-to-export-UID.patch"
SRC_URI += "file://0003-Automatically-restart-display-manager.patch"
SRC_URI += "file://0004-Modifications-for-yocto-build.patch"


do_install_append() {
    install -m 755 uid.sh ${D}/etc/profile.d
    mkdir -p ${D}/lib/systemd/user/default.target.wants
    ln -sf ../weston-user.service ${D}/lib/systemd/user/default.target.wants/weston-user.service
}

pkg_postinst_${PN} () {
    for user in alice bob carol app guest; do
        for appdir in desktop manifest dbspace; do
            mkdir -p $D/home/$user/.applications/$appdir
        done
        find $D/home/$user/ -type d -exec chsmack -a User {} \;
        chown -R $user:users $D/home/$user/
    done
}

weston-common_files += "/lib/systemd/user/default.target.wants/weston-user.service"
weston-common_files += "/home/*"

pkg_preinst_${PN}() {
    #!/bin/sh -e
}
