DESCRIPTION = "Small Embeddable Language with Simple Procedural Syntax"
HOMEPAGE = "http://www.lua.org"
SECTION = "Base/Libraries"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools

PROVIDES = ""

#PROVIDES by lua 

#PROVIDES by lua-dev 

#PROVIDES by liblua 

#PROVIDES by lua-doc 

RDEPENDS = ""
#RDEPENDS of lua-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "lua"


DEPENDS = ""
#DEPENDS of lua 
DEPENDS += "pkgconfig-native"
DEPENDS += "readline-native"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n lua-5.1.4
 cp ${S}/packaging/lua.manifest .
 
 
}
do_patch_append() {
    bb.build.exec_func('do_prep', d)
}

do_configure() {
}

do_compile() {
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" ; export CFLAGS ; 
 CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
 FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
 LD_AS_NEEDED=1; export LD_AS_NEEDED ; 
 
 sed -i 's:LUA_ROOT2 "LIBDIR/lua/5.1/":LUA_ROOT2 \"lib/lua/5.1/":' src/luaconf.h
 make -j16 -C src CC="gcc" MYCFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -fPIC -DLUA_USE_LINUX" MYLIBS="-Wl,-E -ldl -lreadline -lhistory -lncurses" V=5.1 all
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make install INSTALL_TOP="${D}${prefix}" INSTALL_LIB="${D}${prefix}/lib" INSTALL_CMOD=${D}${prefix}/lib/lua/5.1 INSTALL_MAN="${D}${mandir}/man1"
 install -D -m644 etc/lua.pc ${D}${prefix}/lib/pkgconfig/lua.pc
 for file in lua luac ; do
     mv "${D}${prefix}/bin/${file}"        "${D}${prefix}/bin/${file}5.1"
     mv "${D}${mandir}/man1/${file}.1" "${D}${mandir}/man1/${file}5.1.1"
 done
 install -d -m 0755 ${D}${prefix}/lib/lua/5.1
 install -d -m 0755 ${D}${prefix}/share/lua/5.1
 install -D -m644 ${S}/packaging/macros.lua ${D}${sysconfdir}/rpm/macros.lua
 
 chmod +x ${D}/${prefix}/lib/liblua.so.5.1
 
 ln -s lua5.1 ${D}${prefix}/bin/lua
 
 
}

PACKAGES = ""
PACKAGES += "lua"
PACKAGES += "lua-dev"
PACKAGES += "liblua"
PACKAGES += "lua-doc"

lua_files = ""
lua_files += "lua.manifest"
lua_files += "${mandir}/man1/lua5.1.1*"
lua_files += "${mandir}/man1/luac5.1.1*"
lua_files += "${prefix}/bin/lua"
lua_files += "${prefix}/bin/lua5.1"
lua_files += "${prefix}/bin/luac5.1"
lua_files += "${prefix}/lib/lua"
lua_files += "${prefix}/lib/lua/5.1"
lua_files += "${prefix}/share/lua"
lua_files += "${prefix}/share/lua/5.1"
lua_files += "${sysconfdir}/rpm/macros.lua"

lua-dev_files = ""
lua-devel_files += "lua.manifest"
lua-devel_files += "${prefix}/include/lauxlib.h"
lua-devel_files += "${prefix}/include/lua.h"
lua-devel_files += "${prefix}/include/lua.hpp"
lua-devel_files += "${prefix}/include/luaconf.h"
lua-devel_files += "${prefix}/include/lualib.h"
lua-devel_files += "${prefix}/lib/pkgconfig/lua.pc"
lua-devel_files += "${prefix}/lib/liblua.a"
lua-devel_files += "${prefix}/lib/liblua.so"

liblua_files = ""
liblua_files += "lua.manifest"
liblua_files += "${prefix}/lib/liblua.so.5.1"

lua-doc_files = ""
lua-doc_files += "lua.manifest"
lua-doc_files += "doc/*"

FILES_${PN} = "${lua_files}"
FILES_${PN}-devel = "${lua-devel_files}"
FILES_lib${PN} = "${liblua_files}"
FILES_${PN}-doc = "${lua-doc_files}"

PKG_lua= "lua"
PKG_lua-devel= "lua-devel"
PKG_liblua= "liblua"
PKG_lua-doc= "lua-doc"

require lua-extraconf.inc
