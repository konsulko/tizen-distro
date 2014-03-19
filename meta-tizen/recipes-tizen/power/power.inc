DESCRIPTION = "A power library in SLP C API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/API"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by capi-system-power 
PROVIDES += "capi-system-power"
RPROVIDES_capi-system-power += "capi-system-power"

#PROVIDES by capi-system-power-devel 
PROVIDES += "capi-system-power-devel"
RPROVIDES_capi-system-power-devel += "capi-system-power-devel"
RPROVIDES_capi-system-power-devel += "capi-system-power-dev"

RDEPENDS = ""
#RDEPENDS of capi-system-power-devel (capi-system-${PN}-devel)
RDEPENDS_capi-system-${PN}-devel += "capi-system-power"


DEPENDS = ""
#DEPENDS of capi-system-power 
DEPENDS += "cmake"
DEPENDS += "dlog"
DEPENDS += "common"
DEPENDS += "libslp-pm"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(vconf)"

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
 
 cp ${S}/packaging/capi-system-power.manifest .
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
PACKAGES += "capi-system-power"
PACKAGES += "capi-system-power-devel"

capi-system-power_files = ""
capi-system-power_files += "capi-system-power.manifest"
capi-system-power_files += "capi-system-power.manifest"
capi-system-power_files += "/usr/lib/libcapi-system-power.so.*"

capi-system-power-devel_files = ""
capi-system-power-devel_files += "capi-system-power.manifest"
capi-system-power-devel_files += "/usr/include/system/power.h"
capi-system-power-devel_files += "/usr/lib/pkgconfig/*.pc"
capi-system-power-devel_files += "/usr/lib/libcapi-system-power.so"

FILES_${PN} = "${capi-system-power_files}"
FILES_${PN}-devel = "${capi-system-power-devel_files}"

PKG_capi-system-power= "capi-system-power"
PKG_capi-system-power-devel= "capi-system-power-devel"

require power-extraconf.inc
