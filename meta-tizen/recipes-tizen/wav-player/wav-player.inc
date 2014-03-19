DESCRIPTION = "A wav player library in Tizen C API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Multimedia/API"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by capi-media-wav-player-devel 
PROVIDES += "capi-media-wav-player-devel"
RPROVIDES_capi-media-wav-player-devel += "capi-media-wav-player-devel"
RPROVIDES_capi-media-wav-player-devel += "capi-media-wav-player-dev"

#PROVIDES by capi-media-wav-player 
PROVIDES += "capi-media-wav-player"
RPROVIDES_capi-media-wav-player += "capi-media-wav-player"

RDEPENDS = ""
#RDEPENDS of capi-media-wav-player-devel (capi-media-${PN}-devel)
RDEPENDS_capi-media-${PN}-devel += "capi-media-wav-player"


DEPENDS = ""
#DEPENDS of capi-media-wav-player 
DEPENDS += "pkgconfig(capi-media-sound-manager)"
DEPENDS += "libmm-sound"
DEPENDS += "cmake"
DEPENDS += "common"
DEPENDS += "dlog"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-media-wav-player.manifest .
 
 
 
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
PACKAGES += "capi-media-wav-player-devel"
PACKAGES += "capi-media-wav-player"

capi-media-wav-player-devel_files = ""
capi-media-wav-player-devel_files += "capi-media-wav-player.manifest"
capi-media-wav-player-devel_files += "/usr/include/media/*.h"
capi-media-wav-player-devel_files += "/usr/lib/pkgconfig/*.pc"
capi-media-wav-player-devel_files += "/usr/lib/libcapi-media-wav-player.so"

capi-media-wav-player_files = ""
capi-media-wav-player_files += "capi-media-wav-player.manifest"
capi-media-wav-player_files += "/usr/lib/libcapi-media-wav-player.so.*"
capi-media-wav-player_files += "capi-media-wav-player.manifest"

FILES_${PN}-devel = "${capi-media-wav-player-devel_files}"
FILES_${PN} = "${capi-media-wav-player_files}"

PKG_capi-media-wav-player-devel= "capi-media-wav-player-devel"
PKG_capi-media-wav-player= "capi-media-wav-player"

require wav-player-extraconf.inc
