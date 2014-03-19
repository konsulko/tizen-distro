DESCRIPTION = "An Audio Input & Audio Output library in Tizen Native API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Multimedia/API"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by capi-media-audio-io 
PROVIDES += "capi-media-audio-io"
RPROVIDES_capi-media-audio-io += "capi-media-audio-io"

#PROVIDES by capi-media-audio-io-devel 
PROVIDES += "capi-media-audio-io-devel"
RPROVIDES_capi-media-audio-io-devel += "capi-media-audio-io-devel"
RPROVIDES_capi-media-audio-io-devel += "capi-media-audio-io-dev"

RDEPENDS = ""
#RDEPENDS of capi-media-audio-io-devel (capi-media-${PN}-devel)
RDEPENDS_capi-media-${PN}-devel += "capi-media-audio-io"


DEPENDS = ""
#DEPENDS of capi-media-audio-io 
DEPENDS += "pkgconfig(dlog)"
DEPENDS += "cmake"
DEPENDS += "pkgconfig(capi-base-common)"
DEPENDS += "pkgconfig(mm-sound)"
DEPENDS += "pkgconfig(capi-media-sound-manager)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-media-audio-io.manifest .
 
 
 
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
 
 MAJORVER=`echo 0.2.0 | awk 'BEGIN {FS="."}{print $1}'`
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DFULLVER=0.2.0 -DMAJORVER=${MAJORVER}
 
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
PACKAGES += "capi-media-audio-io"
PACKAGES += "capi-media-audio-io-devel"

capi-media-audio-io_files = ""
capi-media-audio-io_files += "capi-media-audio-io.manifest"
capi-media-audio-io_files += "/usr/lib/libcapi-media-audio-io.so.*"
capi-media-audio-io_files += "capi-media-audio-io.manifest"

capi-media-audio-io-devel_files = ""
capi-media-audio-io-devel_files += "capi-media-audio-io.manifest"
capi-media-audio-io-devel_files += "/usr/include/media/audio_io.h"
capi-media-audio-io-devel_files += "/usr/lib/pkgconfig/*.pc"
capi-media-audio-io-devel_files += "/usr/lib/libcapi-media-audio-io.so"

FILES_${PN} = "${capi-media-audio-io_files}"
FILES_${PN}-devel = "${capi-media-audio-io-devel_files}"

PKG_capi-media-audio-io= "capi-media-audio-io"
PKG_capi-media-audio-io-devel= "capi-media-audio-io-devel"

require audio-io-extraconf.inc
