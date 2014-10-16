DEPENDS += "python"

export BUILD_SYS
export HOST_SYS
export STAGING_LIBDIR
export STAGING_INCDIR

do_configure_append() {
    ./configure --prefix=${prefix}
}

do_compile() {
    cd ${S}
    LANG=C
    export LANG
    unset DISPLAY
    LD_AS_NEEDED=1; export LD_AS_NEEDED ;

    oe_runmake -j16
}

PACKAGES += " python-${PN}-dbg "

FILES_python-${PN}-dbg += "${prefix}/lib/python2.7/site-packages/.debug/tdb.so"
