DEPENDS_append_class-native = " tizen-platform-wrapper-native"
DEPENDS_append_class-target = " tizen-platform-wrapper-native"

do_configure() {
 sed -i 's@wrappersrcdir=.*@wrappersrcdir=$(PKG_CONFIG_SYSROOT_DIR)$(datadir)@' ${S}/src/Makefile.am
}
