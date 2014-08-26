EXTRA_OECONF = " \
                --with-dynamic-plugins=domain-control,system-controller,ivi-resource-manager,resource-asm \
                --enable-gpl \
                --enable-pulse \
                --enable-glib \
                --disable-qt \
                --enable-libdbus \
                --enable-telephony \
                --enable-websockets \
                --enable-smack \
                --disable-system-controller \
                --enable-system-monitor \
                "

do_configure_append() {
    ./bootstrap
    autotools_do_configure
}

do_compile() {
    cd ${S}
    LANG=C
    export LANG
    unset DISPLAY
    LD_AS_NEEDED=1; export LD_AS_NEEDED ;

    oe_runmake clean
    oe_runmake
}
