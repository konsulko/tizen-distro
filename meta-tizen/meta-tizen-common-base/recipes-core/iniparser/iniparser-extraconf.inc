EXTRA_OEMAKE = "'CC=${CC} -fPIC' 'MYCFLAGS=${CFLAGS}' MYLDFLAGS='${LDFLAGS}'"

do_compile() {
    cd ${S}
    LANG=C
    export LANG
    unset DISPLAY
    LD_AS_NEEDED=1; export LD_AS_NEEDED ;
    oe_runmake prefix=${prefix}  ${PARALLEL_MAKE} CFLAGS="${CFLAGS} -fPIC"
}