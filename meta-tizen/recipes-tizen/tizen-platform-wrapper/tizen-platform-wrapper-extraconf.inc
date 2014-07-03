do_configure_append_class-native() {
 sed -i "s@\"/etc/tizen-platform.conf\"@\"${sysconfdir}/tizen-platform.conf\"@g" ${S}/src/tzplatform_config.c
 sed -i "s@\"/etc/tizen-platform.conf\"@\"${sysconfdir}/tizen-platform.conf\"@g" ${S}/src/toolbox.c
}
