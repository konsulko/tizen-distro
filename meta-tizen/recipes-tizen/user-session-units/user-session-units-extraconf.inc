do_install_append() {
    rm -f ${D}/lib/systemd/user/dbus.service
    rm -f ${D}/lib/systemd/user/dbus.socket
}

user-session-units_files += "/lib/systemd/user"
