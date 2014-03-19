DESCRIPTION = "WBXML parser and compiler library"
HOMEPAGE = "http://libwbxml.opensync.org/"
SECTION = "System/Libraries"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libwbxml2 
PROVIDES += "libwbxml2"
RPROVIDES_libwbxml2 += "libwbxml2"

#PROVIDES by wbxml2-tools 
PROVIDES += "wbxml2-tools"
RPROVIDES_wbxml2-tools += "wbxml2-tools"

#PROVIDES by libwbxml2-devel 
PROVIDES += "libwbxml2-devel"
RPROVIDES_libwbxml2-devel += "libwbxml2-devel"
RPROVIDES_libwbxml2-devel += "libwbxml2-dev"

RDEPENDS = ""
#RDEPENDS of wbxml2-tools (wbxml2-tools)
RDEPENDS_wbxml2-tools += "libwbxml2"
RDEPENDS_wbxml2-tools += "pkgconfig(libxml-2.0)"

#RDEPENDS of libwbxml2-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libwbxml2"
RDEPENDS_${PN}-devel += "glibc-dev"
RDEPENDS_${PN}-devel += "pkgconfig(libxml-2.0)"
RDEPENDS_${PN}-devel += "pkgconfig(expat)"


DEPENDS = ""
#DEPENDS of libwbxml2 
DEPENDS += "zlib-devel"
DEPENDS += "gcc-cross"
DEPENDS += "pkgconfig(popt)"
DEPENDS += "cmake"
DEPENDS += "pkgconfig(libxml-2.0)"
DEPENDS += "pkgconfig(pkg-config)"
DEPENDS += "expat"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n libwbxml-0.11.2
 cp ${S}/packaging/libwbxml2.manifest .
 
 
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
 
 mkdir build
 pushd build
 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" \
 CXXFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" \
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake \
         -DCMAKE_BUILD_TYPE=None \
         -DENABLE_INSTALL_DOC:BOOL=OFF \
          ${WORKDIR}/libwbxml-0.11.2
 make -j16 VERBOSE=1
 popd
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 pushd build
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 popd
 
 
}

PACKAGES = ""
PACKAGES += "libwbxml2"
PACKAGES += "wbxml2-tools"
PACKAGES += "libwbxml2-devel"

libwbxml2_files = ""
libwbxml2_files += "libwbxml2.manifest"
libwbxml2_files += "/usr/lib/libwbxml2.so.1*"

wbxml2-tools_files = ""
wbxml2-tools_files += "libwbxml2.manifest"
wbxml2-tools_files += "/usr/bin/wbxml2xml"
wbxml2-tools_files += "/usr/bin/xml2wbxml"

libwbxml2-devel_files = ""
libwbxml2-devel_files += "libwbxml2.manifest"
libwbxml2-devel_files += "/usr/lib/pkgconfig/libwbxml2.pc"
libwbxml2-devel_files += "/usr/lib/libwbxml2.so"
libwbxml2-devel_files += "/usr/include/libwbxml-1.0/wbxml"
libwbxml2-devel_files += "/usr/share/cmake/Modules/FindLibWbxml2.cmake"
libwbxml2-devel_files += "/usr/include/wbxml_config.h"

FILES_${PN} = "${libwbxml2_files}"
FILES_wbxml2-tools = "${wbxml2-tools_files}"
FILES_${PN}-devel = "${libwbxml2-devel_files}"

PKG_libwbxml2= "libwbxml2"
PKG_wbxml2-tools= "wbxml2-tools"
PKG_libwbxml2-devel= "libwbxml2-devel"

require libwbxml2-extraconf.inc
