INSANE_SKIP_${PN}-dev = "staticdev"

EXTRA_OEMAKE = "'CC=${CC} -fPIC' 'MYCFLAGS=${CFLAGS} -DLUA_USE_LINUX -fPIC' MYLDFLAGS='${LDFLAGS}'"

inherit gettext

do_compile() {
    cd ${S}
    LANG=C
    export LANG
    unset DISPLAY
    LD_AS_NEEDED=1; export LD_AS_NEEDED ;
    sed -i 's:LUA_ROOT2 "LIBDIR/lua/5.1/":LUA_ROOT2 \"lib/lua/5.1/":' src/luaconf.h
    oe_runmake ${PARALLEL_MAKE} -C src CC="${CC}" MYCFLAGS="${CFLAGS} -fPIC -DLUA_USE_LINUX" MYLIBS="-Wl,-E -ldl -lreadline -lhistory -lncurses" V=5.1 all
}
