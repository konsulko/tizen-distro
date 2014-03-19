DESCRIPTION = "A Media content library in SLP C API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Multimedia/API"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by capi-content-media-content 
PROVIDES += "capi-content-media-content"
RPROVIDES_capi-content-media-content += "capi-content-media-content"

#PROVIDES by capi-content-media-content-devel 
PROVIDES += "capi-content-media-content-devel"
RPROVIDES_capi-content-media-content-devel += "capi-content-media-content-devel"
RPROVIDES_capi-content-media-content-devel += "capi-content-media-content-dev"

RDEPENDS = ""
#RDEPENDS of capi-content-media-content-devel (capi-content-${PN}-devel)
RDEPENDS_capi-content-${PN}-devel += "capi-content-media-content"


DEPENDS = ""
#DEPENDS of capi-content-media-content 
DEPENDS += "libmedia-thumbnail"
DEPENDS += "cmake"
DEPENDS += "pkgconfig(libmedia-utils)"
DEPENDS += "dlog"
DEPENDS += "common"
DEPENDS += "libmedia-service"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-content-media-content.manifest .
 
 
 
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
 
 MAJORVER=`echo 0.2.58 | awk 'BEGIN {FS="."}{print $1}'`
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DFULLVER=0.2.58 -DMAJORVER=${MAJORVER}
 
 
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 #License
 
 
}

PACKAGES = ""
PACKAGES += "capi-content-media-content"
PACKAGES += "capi-content-media-content-devel"

capi-content-media-content_files = ""
capi-content-media-content_files += "capi-content-media-content.manifest"
capi-content-media-content_files += "capi-content-media-content.manifest"
capi-content-media-content_files += "/usr/lib/libcapi-content-media-content.so.*"

capi-content-media-content-devel_files = ""
capi-content-media-content-devel_files += "capi-content-media-content.manifest"
capi-content-media-content-devel_files += "/usr/include/media-content/*.h"
capi-content-media-content-devel_files += "/usr/lib/pkgconfig/*.pc"
capi-content-media-content-devel_files += "/usr/lib/libcapi-content-media-content.so"

FILES_${PN} = "${capi-content-media-content_files}"
FILES_${PN}-devel = "${capi-content-media-content-devel_files}"

PKG_capi-content-media-content= "capi-content-media-content"
PKG_capi-content-media-content-devel= "capi-content-media-content-devel"

require media-content-extraconf.inc
