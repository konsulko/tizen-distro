SRC_URI += "file://0001-Add-env-value-SYSROOT-for-root-fs-prefix.patch"

do_configure_append_class-native() {
 sed -i "s@\"/etc/tizen-platform.conf\"@\"${sysconfdir}/tizen-platform.conf\"@g" ${S}/src/init.c
 sed -i "s@\"/etc/tizen-platform.conf\"@\"${sysconfdir}/tizen-platform.conf\"@g" ${S}/src/toolbox.c
}


