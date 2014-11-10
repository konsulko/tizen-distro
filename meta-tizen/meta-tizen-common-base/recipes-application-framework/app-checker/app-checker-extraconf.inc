FILESEXTRAPATHS_prepend := "${THISDIR}/app-checker:"

SRC_URI += "file://0001-yocto-Correct-libdl-linking-issue.patch"
SRC_URI_append_class-native = " file://remove-dlog-for-native-build.patch"

DEPENDS_remove_class-native = "dlog-native"

export LDFLAGS_append_class-native = " -ldl"

DEPENDS += "binutils-native"