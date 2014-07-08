ail_files += "/usr/dbspace"

SRC_URI_append_class-native = " file://remove-dlog-for-native-build.patch"

RDEPENDS_${PN}_remove_class-native = "systemd-native"
DEPENDS_remove_class-native = "dlog-native"

DEPENDS_class-target += " ail-native"