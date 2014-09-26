do_compile() {
    cd ${S}
    LANG=C
    export LANG
    unset DISPLAY
    LD_AS_NEEDED=1; export LD_AS_NEEDED ;

    cp -f ${PKG_CONFIG_SYSROOT_DIR}${datadir}/libtool/config/config.guess ${WORKDIR}
    cp -f ${PKG_CONFIG_SYSROOT_DIR}${datadir}/libtool/config/config.sub ${WORKDIR}

    autotools_do_configure \
        --build=${TARGET_SYS} \
        --host=${HOST_SYS} \
        --target=x86_64-tizen-linux \
        --program-prefix= \
        --prefix=${prefix} \
        --exec-prefix=${prefix} \
        --bindir=${prefix}/bin \
        --sbindir=${prefix}/sbin \
        --sysconfdir=${sysconfdir} \
        --datadir=${prefix}/share \
        --includedir=${prefix}/include \
        --libdir=${prefix}/lib \
        --libexecdir=${prefix}/libexec \
        --localstatedir=${localstatedir} \
        --sharedstatedir=${prefix}/com \
        --mandir=${mandir} \
        --infodir=${infodir} --disable-static

    make -j16
}
