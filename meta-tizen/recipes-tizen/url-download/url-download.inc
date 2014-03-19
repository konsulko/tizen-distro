DESCRIPTION = "CAPI for content download with web url"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Development/Libraries"
LICENSE = "Apache License, Version 2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by capi-web-url-download 
PROVIDES += "capi-web-url-download"
RPROVIDES_capi-web-url-download += "capi-web-url-download"

#PROVIDES by capi-web-url-download-devel 
PROVIDES += "capi-web-url-download-devel"
RPROVIDES_capi-web-url-download-devel += "capi-web-url-download-devel"
RPROVIDES_capi-web-url-download-devel += "capi-web-url-download-dev"

RDEPENDS = ""
#RDEPENDS of capi-web-url-download-devel (capi-web-${PN}-devel)
RDEPENDS_capi-web-${PN}-devel += "capi-web-url-download"


DEPENDS = ""
#DEPENDS of capi-web-url-download 
DEPENDS += "download-provider"
DEPENDS += "cmake"
DEPENDS += "common"
DEPENDS += "dlog"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-web-url-download.manifest .
 
 
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
 mkdir -p ${D}/usr/share/license
 
 
}

PACKAGES = ""
PACKAGES += "capi-web-url-download"
PACKAGES += "capi-web-url-download-devel"

capi-web-url-download_files = ""
capi-web-url-download_files += "capi-web-url-download.manifest"
capi-web-url-download_files += "/usr/lib/libcapi-web-url-download.so.*"
capi-web-url-download_files += "/usr/share/license/capi-web-url-download"

capi-web-url-download-devel_files = ""
capi-web-url-download-devel_files += "capi-web-url-download.manifest"
capi-web-url-download-devel_files += "capi-web-url-download.manifest"
capi-web-url-download-devel_files += "/usr/lib/libcapi-web-url-download.so"
capi-web-url-download-devel_files += "/usr/lib/pkgconfig/capi-web-url-download.pc"
capi-web-url-download-devel_files += "/usr/include/web/download.h"

FILES_${PN} = "${capi-web-url-download_files}"
FILES_${PN}-devel = "${capi-web-url-download-devel_files}"

PKG_capi-web-url-download= "capi-web-url-download"
PKG_capi-web-url-download-devel= "capi-web-url-download-devel"

require url-download-extraconf.inc
