DEPENDS_append_class-native = " tizen-platform-wrapper-native"
DEPENDS_append_class-target = " tizen-platform-wrapper-native"

do_configure() {
 sed -i 's@wrappersrcdir=.*@wrappersrcdir=$(PKG_CONFIG_SYSROOT_DIR)$(datadir)@' ${S}/src/Makefile.am
}

do_install_append_class-native() {
 sed -i "s@=/home@=${D}/home@g" ${D}${sysconfdir}/tizen-platform.conf
 sed -i "s@=/opt@=${D}/opt@g" ${D}${sysconfdir}/tizen-platform.conf
 sed -i "s@=/usr@=${D}/usr@g" ${D}${sysconfdir}/tizen-platform.conf
 sed -i "s@=/etc@=${D}/etc@g" ${D}${sysconfdir}/tizen-platform.conf
 sed -i "s@=/root@=${D}/root@g" ${D}${sysconfdir}/tizen-platform.conf
}

