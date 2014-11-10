SRC_URI_append_class-native = " file://remove-dlog-for-native.patch"

RDEPENDS_${PN}_remove_class-native = "glibc-native"
RDEPENDS_${PN}_remove_class-native = "systemd-native"
DEPENDS_remove_class-native = "dlog-native"

DEPENDS_class-target += "glib-2.0"
DEPENDS_class-target += "vconf-native"
DEPENDS_class-target += "vconf-internal-keys"
DEPENDS_class-target += "dlog"

do_install_append_class-native() {
 sed -i "s@source /etc/tizen-platform.conf@source ${sysconfdir}/tizen-platform.conf@g" ${D}${prefix}/bin/vconf-init
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    [ "x\$D" == "x" ] && ldconfig
    [ "x\$D" == "x" ] && systemctl daemon-reload
    chsmack -a 'User' $D${prefix}/kdb
    chsmack -a 'User' $D${prefix}/kdb/db
    chsmack -a 'User' $D${prefix}/kdb/db/.backup

}