INSANE_SKIP_libtzplatform-config-dev = "staticdev"

DEPENDS_append_class-native = " tizen-platform-wrapper-native"
DEPENDS_append_class-target = " tizen-platform-wrapper-native"

do_configure() {
 sed -i 's@wrappersrcdir=.*@wrappersrcdir=$(PKG_CONFIG_SYSROOT_DIR)$(datadir)@' ${S}/src/Makefile.am
}

do_install_append() {
 sed -i "s@=/home@=\$SYSROOT/home@g" ${D}${sysconfdir}/tizen-platform.conf
 sed -i "s@=/opt@=\$SYSROOT/opt@g" ${D}${sysconfdir}/tizen-platform.conf
 sed -i "s@=/usr@=\$SYSROOT/usr@g" ${D}${sysconfdir}/tizen-platform.conf
 sed -i "s@=/etc@=\$SYSROOT/etc@g" ${D}${sysconfdir}/tizen-platform.conf
 sed -i "s@=/root@=\$SYSROOT/root@g" ${D}${sysconfdir}/tizen-platform.conf
 sed -i "s@=/var@=\$SYSROOT/var@g" ${D}${sysconfdir}/tizen-platform.conf
 
}

