FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

SRC_URI += " file://dbus-user.service \
             file://dbus-user.socket \
           "

do_install_append() {
	mkdir -p ${D}${systemd_unitdir}/user
	install -m 0644 ${WORKDIR}/dbus-user.service ${D}${systemd_unitdir}/user/dbus.service
	install -m 0644 ${WORKDIR}/dbus-user.socket ${D}${systemd_unitdir}/user/dbus.socket
}

FILES_${PN} += "${systemd_unitdir}/user/dbus.service \
               ${systemd_unitdir}/user/dbus.socket \
              "