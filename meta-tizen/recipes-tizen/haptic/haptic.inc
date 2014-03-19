DESCRIPTION = "A Haptic library in Tizen C API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/API"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by capi-system-haptic 
PROVIDES += "capi-system-haptic"
RPROVIDES_capi-system-haptic += "capi-system-haptic"

#PROVIDES by capi-system-haptic-devel 
PROVIDES += "capi-system-haptic-devel"
RPROVIDES_capi-system-haptic-devel += "capi-system-haptic-devel"
RPROVIDES_capi-system-haptic-devel += "capi-system-haptic-dev"

RDEPENDS = ""
#RDEPENDS of capi-system-haptic-devel (capi-system-${PN}-devel)
RDEPENDS_capi-system-${PN}-devel += "capi-system-haptic"


DEPENDS = ""
#DEPENDS of capi-system-haptic 
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "cmake"
DEPENDS += "devman"
DEPENDS += "dlog"
DEPENDS += "common"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 
 
 
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
 
 cp ${S}/packaging/capi-system-haptic.manifest .
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
PACKAGES += "capi-system-haptic"
PACKAGES += "capi-system-haptic-devel"

capi-system-haptic_files = ""
capi-system-haptic_files += "capi-system-haptic.manifest"
capi-system-haptic_files += "capi-system-haptic.manifest"
capi-system-haptic_files += "/usr/lib/libcapi-system-haptic.so.*"

capi-system-haptic-devel_files = ""
capi-system-haptic-devel_files += "capi-system-haptic.manifest"
capi-system-haptic-devel_files += "/usr/include/system/*.h"
capi-system-haptic-devel_files += "/usr/lib/pkgconfig/*.pc"
capi-system-haptic-devel_files += "/usr/lib/libcapi-system-haptic.so"

FILES_${PN} = "${capi-system-haptic_files}"
FILES_${PN}-devel = "${capi-system-haptic-devel_files}"

PKG_capi-system-haptic= "capi-system-haptic"
PKG_capi-system-haptic-devel= "capi-system-haptic-devel"

require haptic-extraconf.inc
