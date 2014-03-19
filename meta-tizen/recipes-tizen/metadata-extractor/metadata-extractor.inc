DESCRIPTION = "A media metadata extractor library in SLP C API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Multimedia/API"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by capi-media-metadata-extractor-devel 
PROVIDES += "capi-media-metadata-extractor-devel"
RPROVIDES_capi-media-metadata-extractor-devel += "capi-media-metadata-extractor-devel"
RPROVIDES_capi-media-metadata-extractor-devel += "capi-media-metadata-extractor-dev"

#PROVIDES by capi-media-metadata-extractor 
PROVIDES += "capi-media-metadata-extractor"
RPROVIDES_capi-media-metadata-extractor += "capi-media-metadata-extractor"

RDEPENDS = ""
#RDEPENDS of capi-media-metadata-extractor-devel (capi-media-${PN}-devel)
RDEPENDS_capi-media-${PN}-devel += "capi-media-metadata-extractor"


DEPENDS = ""
#DEPENDS of capi-media-metadata-extractor 
DEPENDS += "libmm-fileinfo"
DEPENDS += "cmake"
DEPENDS += "common"
DEPENDS += "dlog"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-media-metadata-extractor.manifest .
 
 
 
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
 
 MAJORVER=`echo 0.1.0 | awk 'BEGIN {FS="."}{print $1}'`
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DFULLVER=0.1.0 -DMAJORVER=${MAJORVER}
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
 
 
 
}

PACKAGES = ""
PACKAGES += "capi-media-metadata-extractor-devel"
PACKAGES += "capi-media-metadata-extractor"

capi-media-metadata-extractor-devel_files = ""
capi-media-metadata-extractor-devel_files += "capi-media-metadata-extractor.manifest"
capi-media-metadata-extractor-devel_files += "/usr/include/media/*.h"
capi-media-metadata-extractor-devel_files += "/usr/lib/pkgconfig/capi-media-metadata-extractor.pc"

capi-media-metadata-extractor_files = ""
capi-media-metadata-extractor_files += "capi-media-metadata-extractor.manifest"
capi-media-metadata-extractor_files += "capi-media-metadata-extractor.manifest"
capi-media-metadata-extractor_files += "/usr/lib/libcapi-media-metadata-extractor.so"

FILES_${PN}-devel = "${capi-media-metadata-extractor-devel_files}"
FILES_${PN} = "${capi-media-metadata-extractor_files}"

PKG_capi-media-metadata-extractor-devel= "capi-media-metadata-extractor-devel"
PKG_capi-media-metadata-extractor= "capi-media-metadata-extractor"

require metadata-extractor-extraconf.inc
