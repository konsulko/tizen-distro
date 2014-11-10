do_configure() {
 sed -i 's@source /etc/tizen-platform.conf@source ${STAGING_DIR_NATIVE}/etc/tizen-platform.conf@' ${S}/db/updater.sh
}
CFLAGS += " -Wno-implicit-function-declaration"

DEPENDS_remove_class-native = "dlog-native"

SRC_URI_append_class-native = " file://remove-dlog-for-native-build.patch"
SRC_URI_append_class-native = " file://missing_header.patch"
