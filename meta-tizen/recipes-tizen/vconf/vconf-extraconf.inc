SRC_URI_append_class-native = " file://remove-dlog-for-native.patch"

RDEPENDS_${PN}_remove_class-native = "eglibc-native"
RDEPENDS_${PN}_remove_class-native = "systemd-native"
DEPENDS_remove_class-native = "dlog-native"

DEPENDS_class-target += "vconf-native"

do_install_append_class-native() {
 sed -i "s@source /etc/tizen-platform.conf@source ${sysconfdir}/tizen-platform.conf@g" ${D}${prefix}/bin/vconf-init
}
