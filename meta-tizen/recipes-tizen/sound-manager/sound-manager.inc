DESCRIPTION = "Sound Manager library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Multimedia/API"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by capi-media-sound-manager-devel 
PROVIDES += "capi-media-sound-manager-devel"
RPROVIDES_capi-media-sound-manager-devel += "capi-media-sound-manager-devel"
RPROVIDES_capi-media-sound-manager-devel += "capi-media-sound-manager-dev"

#PROVIDES by capi-media-sound-manager 
PROVIDES += "capi-media-sound-manager"
RPROVIDES_capi-media-sound-manager += "capi-media-sound-manager"

RDEPENDS = ""
#RDEPENDS of capi-media-sound-manager-devel (capi-media-${PN}-devel)
RDEPENDS_capi-media-${PN}-devel += "capi-media-sound-manager"


DEPENDS = ""
#DEPENDS of capi-media-sound-manager 
DEPENDS += "libmm-sound"
DEPENDS += "cmake"
DEPENDS += "libmm-session"
DEPENDS += "dlog"
DEPENDS += "common"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-media-sound-manager.manifest .
 
 
 
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
 
 MAJORVER=`echo 0.1.1 | awk 'BEGIN {FS="."}{print $1}'`
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DFULLVER=0.1.1 -DMAJORVER=${MAJORVER}
 
 
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
PACKAGES += "capi-media-sound-manager-devel"
PACKAGES += "capi-media-sound-manager"

capi-media-sound-manager-devel_files = ""
capi-media-sound-manager-devel_files += "capi-media-sound-manager.manifest"
capi-media-sound-manager-devel_files += "/usr/include/media/sound_manager.h"
capi-media-sound-manager-devel_files += "/usr/lib/pkgconfig/*.pc"
capi-media-sound-manager-devel_files += "/usr/lib/libcapi-media-sound-manager.so"

capi-media-sound-manager_files = ""
capi-media-sound-manager_files += "capi-media-sound-manager.manifest"
capi-media-sound-manager_files += "/usr/lib/libcapi-media-sound-manager.so.*"
capi-media-sound-manager_files += "capi-media-sound-manager.manifest"

FILES_${PN}-devel = "${capi-media-sound-manager-devel_files}"
FILES_${PN} = "${capi-media-sound-manager_files}"

PKG_capi-media-sound-manager-devel= "capi-media-sound-manager-devel"
PKG_capi-media-sound-manager= "capi-media-sound-manager"

require sound-manager-extraconf.inc
