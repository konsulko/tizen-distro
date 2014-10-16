SRC_URI += "file://fix-include-directories-in-CMakeList.txt.patch"
SRC_URI += "file://fix-include-directories-in-CMakeList_2.patch"

SRC_URI_append_class-native = " file://remove-dlog-for-native-build.patch"

INSANE_SKIP_${PN} = "already-stripped dev-so"
INSANE_SKIP_privacy-manager-client = "dev-so"

do_configure() {
 sed -i 's@source /etc/tizen-platform.conf@source $D/etc/tizen-platform.conf@' ${S}/res/usr/bin/privacy_manager_create_clean_db.sh
}

DEPENDS += "binutils-native"
DEPENDS_remove_class-native = "dlog-native"
RDEPENDS_${PN}_remove_class-native = "glibc-native"

EXTRA_OECMAKE+="-DCMAKE_STRIP:PATH=strip"