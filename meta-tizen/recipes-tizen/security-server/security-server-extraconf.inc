SRC_URI += "file://0001-PATCH-link-to-the-pthread-library.patch"
SRC_URI_append_class-native = " file://remove-dlog-for-native-build.patch"

CXXFLAGS += "-std=c++11"

RDEPENDS_${PN}_remove_class-native = "systemd-native"
DEPENDS_remove_class-native = "systemd-native"
DEPENDS_remove_class-native = "dlog-native"
