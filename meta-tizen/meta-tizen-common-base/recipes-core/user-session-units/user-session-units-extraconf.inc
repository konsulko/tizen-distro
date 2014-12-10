FILESEXTRAPATHS_append := "${THISDIR}/user-session-units"

do_install_append() {
    rm -f ${D}${prefix}/lib/systemd/user/dbus.socket

    mkdir -p ${D}${prefix}/lib/systemd/user/default.target.wants
    ln -sf ../dbus.service ${D}${prefix}/lib/systemd/user/default.target.wants/dbus.service
    rm ${D}${prefix}/lib/systemd/user/dbus.service
}

user-session-units_files += "${prefix}/lib/systemd/user/default.target.wants/dbus.service"
user-session-units_files += "${prefix}/lib/systemd/user/dbus.service"
FILES_${PN}-kde += "${prefix}/lib/systemd/user/kde.target.wants/startkde.service"
FILES_${PN}-kde += "${prefix}/lib/systemd/user/startkde.service"
FILES_${PN}-kde += "${prefix}/lib/systemd/user/kde.target"