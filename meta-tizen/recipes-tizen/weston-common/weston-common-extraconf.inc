inherit useradd

FILESEXTRAPATHS_append := "${THISDIR}/weston-common"

SRC_URI += "file://0001-Yocto-correct-paths-to-ln-and-chmod.patch"
SRC_URI += "file://0002-Add-a-script-to-export-UID.patch"
SRC_URI += "file://0003-Automatically-restart-display-manager.patch"
SRC_URI += "file://0004-Modifications-for-yocto-build.patch"
SRC_URI += "file://0005-fix_weston_start.patch"

USERADD_PACKAGES = "${PN}"

GROUPADD_PARAM_${PN} = "-g 191 display;-g 100 users;-g 1004 input;-g 190 systemd-journal;-g 54 lock"

USERADD_PARAM_${PN} = "  -d /run/display -m  -u 115  -g display -G users,input,tty,display  -s /bin/sh display; "
USERADD_PARAM_${PN} += " -d /home/alice -m -u 5001   -g users   -G users,display -r -s /bin/sh alice; "
USERADD_PARAM_${PN} += " -d /home/bob   -m -u 5002   -g users   -G users,display -r -s /bin/sh bob; "
USERADD_PARAM_${PN} += " -d /home/carole -m -u 5003   -g users   -G users,display -r -s /bin/sh carole; "
USERADD_PARAM_${PN} += " -d /home/guest -m -u 9999   -g users   -G users,display -r -s /bin/sh guest "

do_install_append() {

    # user 'display' must own /dev/tty7 for weston to start correctly
    cat >${D}${sysconfdir}/udev/rules.d/99-tty.rules <<'EOF'
    SUBSYSTEM=="tty", KERNEL=="tty7", OWNER="display", SMACK="*"
EOF

    # user 'display' must also be able to access /dev/input/event*
    cat >${D}${sysconfdir}/udev/rules.d/99-input.rules <<'EOF'
    SUBSYSTEM=="input", KERNEL=="event*", MODE="0660", GROUP="input", SMACK="*"
EOF

    install -m 755 uid.sh ${D}/etc/profile.d

    mkdir -p ${D}/lib/systemd/user/default.target.wants
    ln -sf ../weston-user.service ${D}/lib/systemd/user/default.target.wants/weston-user.service
}

pkg_postinst_${PN} () {
    for user in alice bob carol app guest; do
        for appdir in desktop manifest dbspace; do
            mkdir -p ${D}/home/$user/.applications/$appdir
        done
        find ${D}/home/$user/ -type d -exec chsmack -a User {} \;
        chown -R $user:users ${D}/home/$user/
    done
}

weston-common_files += "/lib/systemd/user/default.target.wants/weston-user.service"
weston-common_files += "/home/*"
