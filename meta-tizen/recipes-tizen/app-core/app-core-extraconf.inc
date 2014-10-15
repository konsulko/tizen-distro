app-core-common_files += "app-core.manifest"
app-core-common_files += "/lib/libappcore-common.so.*"
app-core-common_files += "/lib/systemd/user/core-efl.target"
app-core-common_files += "/lib/systemd/user/core-efl.target.wants/"
app-core-common_files += "/usr/share/license/app-core"

SRC_URI_append_class-native = " file://remove-dlog-for-native-build.patch"
DEPENDS_remove_class-native = "dlog-native"