DESCRIPTION = "Small Embeddable Language with Simple Procedural Syntax"
HOMEPAGE = "http://www.lua.org"
SECTION = "Base/Libraries"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by lua 
PROVIDES += "lua"
RPROVIDES_lua += "lua"

#PROVIDES by lua-devel 
PROVIDES += "lua-devel"
RPROVIDES_lua-devel += "lua-devel"
RPROVIDES_lua-devel += "lua-dev"

#PROVIDES by liblua 
PROVIDES += "liblua"
RPROVIDES_liblua += "liblua"

#PROVIDES by lua-doc 
PROVIDES += "lua-doc"
RPROVIDES_lua-doc += "lua-doc"

RDEPENDS = ""
#RDEPENDS of lua-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "lua"


DEPENDS = ""
#DEPENDS of lua 
DEPENDS += "pkgconfig-native"
DEPENDS += "readline-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n lua-5.1.4
 cp ${S}/packaging/lua.manifest .
 
 
}

do_configure() {
}

do_compile() {
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
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make install INSTALL_TOP="${D}/usr" INSTALL_LIB="${D}/usr/lib" INSTALL_CMOD=${D}/usr/lib/lua/5.1 INSTALL_MAN="${D}/usr/share/man/man1"
 install -D -m644 etc/lua.pc ${D}/usr/lib/pkgconfig/lua.pc
 for file in lua luac ; do
     mv "${D}/usr/bin/${file}"        "${D}/usr/bin/${file}5.1"
     mv "${D}/usr/share/man/man1/${file}.1" "${D}/usr/share/man/man1/${file}5.1.1"
 done
 install -d -m 0755 ${D}/usr/lib/lua/5.1
 install -d -m 0755 ${D}/usr/share/lua/5.1
 install -D -m644 ${S}/packaging/macros.lua ${D}/etc/rpm/macros.lua
 
 chmod +x ${D}//usr/lib/liblua.so.5.1
 
 ln -s lua5.1 ${D}/usr/bin/lua
 
 
}

PACKAGES = ""
PACKAGES += "lua"
PACKAGES += "lua-devel"
PACKAGES += "liblua"
PACKAGES += "lua-doc"

lua_files = ""
lua_files += "lua.manifest"
lua_files += "/usr/share/man/man1/lua5.1.1*"
lua_files += "/usr/share/man/man1/luac5.1.1*"
lua_files += "/usr/bin/lua"
lua_files += "/usr/bin/lua5.1"
lua_files += "/usr/bin/luac5.1"
lua_files += "/usr/lib/lua"
lua_files += "/usr/lib/lua/5.1"
lua_files += "/usr/share/lua"
lua_files += "/usr/share/lua/5.1"
lua_files += "/etc/rpm/macros.lua"

lua-devel_files = ""
lua-devel_files += "lua.manifest"
lua-devel_files += "/usr/include/lauxlib.h"
lua-devel_files += "/usr/include/lua.h"
lua-devel_files += "/usr/include/lua.hpp"
lua-devel_files += "/usr/include/luaconf.h"
lua-devel_files += "/usr/include/lualib.h"
lua-devel_files += "/usr/lib/pkgconfig/lua.pc"
lua-devel_files += "/usr/lib/liblua.a"
lua-devel_files += "/usr/lib/liblua.so"

liblua_files = ""
liblua_files += "lua.manifest"
liblua_files += "/usr/lib/liblua.so.5.1"

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
