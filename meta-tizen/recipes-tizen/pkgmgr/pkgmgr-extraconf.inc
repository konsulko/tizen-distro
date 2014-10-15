SRC_URI_append_class-native = " file://remove-dlog-for-native-build.patch"

do_install_append() {
 rm -fr "${D}${prefix}/bin/pkgcmd.real"
 rm -fr "${D}${prefix}/bin/pkgcmd.wrapper"
}

RDEPENDS_${PN}_remove_class-native = "systemd-native"
DEPENDS_remove_class-native = "dlog-native"

EXTRA_OECMAKE+="-DCMAKE_AR:PATH=ar"