DESCRIPTION = "A tone player library in Tizen C API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Multimedia/API"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by capi-media-tone-player-devel 
PROVIDES += "capi-media-tone-player-devel"
RPROVIDES_capi-media-tone-player-devel += "capi-media-tone-player-devel"
RPROVIDES_capi-media-tone-player-devel += "capi-media-tone-player-dev"

#PROVIDES by capi-media-tone-player 
PROVIDES += "capi-media-tone-player"
RPROVIDES_capi-media-tone-player += "capi-media-tone-player"

RDEPENDS = ""
#RDEPENDS of capi-media-tone-player-devel (capi-media-${PN}-devel)
RDEPENDS_capi-media-${PN}-devel += "capi-media-tone-player"


DEPENDS = ""
#DEPENDS of capi-media-tone-player 
DEPENDS += "pkgconfig(capi-media-sound-manager)"
DEPENDS += "libmm-sound"
DEPENDS += "cmake"
DEPENDS += "common"
DEPENDS += "dlog"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-media-tone-player.manifest .
 
 
 
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
PACKAGES += "capi-media-tone-player-devel"
PACKAGES += "capi-media-tone-player"

capi-media-tone-player-devel_files = ""
capi-media-tone-player-devel_files += "capi-media-tone-player.manifest"
capi-media-tone-player-devel_files += "/usr/include/media/*.h"
capi-media-tone-player-devel_files += "/usr/lib/pkgconfig/*.pc"
capi-media-tone-player-devel_files += "/usr/lib/libcapi-media-tone-player.so"

capi-media-tone-player_files = ""
capi-media-tone-player_files += "capi-media-tone-player.manifest"
capi-media-tone-player_files += "capi-media-tone-player.manifest"
capi-media-tone-player_files += "/usr/lib/libcapi-media-tone-player.so.*"

FILES_${PN}-devel = "${capi-media-tone-player-devel_files}"
FILES_${PN} = "${capi-media-tone-player_files}"

PKG_capi-media-tone-player-devel= "capi-media-tone-player-devel"
PKG_capi-media-tone-player= "capi-media-tone-player"

require tone-player-extraconf.inc
