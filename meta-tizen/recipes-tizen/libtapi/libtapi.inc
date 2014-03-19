DESCRIPTION = "Telephony dbus client library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libtapi-devel 
PROVIDES += "libtapi-devel"
RPROVIDES_libtapi-devel += "libtapi-devel"
RPROVIDES_libtapi-devel += "libtapi-dev"

#PROVIDES by libtapi 
PROVIDES += "libtapi"
RPROVIDES_libtapi += "libtapi"

RDEPENDS = ""
#RDEPENDS of libtapi-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libtapi"


DEPENDS = ""
#DEPENDS of libtapi 
DEPENDS += "pkgconfig(gobject-2.0)"
DEPENDS += "pkgconfig(security-server)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "cmake"
DEPENDS += "dlog"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libtapi.manifest .
 
 
 
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
 
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export FFLAGS ; 
   cmake \
         -DCMAKE_VERBOSE_MAKEFILE=ON \
         -DCMAKE_INSTALL_PREFIX:PATH=/usr \
         -DCMAKE_INSTALL_LIBDIR:PATH=/usr/lib \
         -DINCLUDE_INSTALL_DIR:PATH=/usr/include \
         -DLIB_INSTALL_DIR:PATH=/usr/lib \
         -DSYSCONF_INSTALL_DIR:PATH=/etc \
         -DSHARE_INSTALL_PREFIX:PATH=/usr/share \
         -DCMAKE_SKIP_RPATH:BOOL=ON \
         -DBUILD_SHARED_LIBS:BOOL=ON \
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake .
 
 
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf ${D}
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 rm -rf ${D}/usr/include/telephony/tapi/.gitignore
 mkdir -p ${D}/usr/share/license
 
 
}

PACKAGES = ""
PACKAGES += "libtapi-devel"
PACKAGES += "libtapi"

libtapi-devel_files = ""
libtapi-devel_files += "libtapi.manifest"
libtapi-devel_files += "/usr/include/telephony-client/*.h"
libtapi-devel_files += "/usr/lib/pkgconfig/*.pc"
libtapi-devel_files += "/usr/lib/*.so"

libtapi_files = ""
libtapi_files += "libtapi.manifest"
libtapi_files += "/usr/lib/*.so.*"
libtapi_files += "/usr/share/license/libtapi"

FILES_${PN}-devel = "${libtapi-devel_files}"
FILES_${PN} = "${libtapi_files}"

PKG_libtapi-devel= "libtapi-devel"
PKG_libtapi= "libtapi"

require libtapi-extraconf.inc
