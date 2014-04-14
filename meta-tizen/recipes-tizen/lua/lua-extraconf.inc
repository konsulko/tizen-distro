TARGET_CC_ARCH += " -fPIC ${LDFLAGS}"
EXTRA_OEMAKE = "'CC=${CC} -fPIC' 'MYCFLAGS=${CFLAGS} -DLUA_USE_LINUX -fPIC' MYLDFLAGS='${LDFLAGS}' V=5.1"

BBCLASSEXTEND = "nativesdk"

do_configure_prepend() {
    sed -i -e s:/usr/local:${prefix}:g src/luaconf.h
    sed -i -e s:lib/lua/5.1/:${base_libdir}/lua/5.1/:g src/luaconf.h
}

do_compile () {
    oe_runmake linux
}

do_install () {
    oe_runmake \
        'INSTALL_TOP=${D}${prefix}' \
        'INSTALL_BIN=${D}${bindir}' \
        'INSTALL_INC=${D}${includedir}/' \
        'INSTALL_MAN=${D}${mandir}/man1' \
        'INSTALL_SHARE=${D}${datadir}/lua' \
        'INSTALL_LIB=${D}${libdir}' \
        'INSTALL_CMOD=${D}${libdir}/lua/5.1' \
        install
    install -d ${D}${libdir}/pkgconfig
    install -m 0644 ${S}/etc/lua.pc ${D}${libdir}/pkgconfig/lua.pc
    rmdir ${D}${libdir}/lua/5.1
    rmdir ${D}${libdir}/lua
    rmdir ${D}${datadir}/lua/5.1
    rmdir ${D}${datadir}/lua

    rm  ${D}${bindir}/luac
}

lua-doc_files += "/usr/share/man/man1"