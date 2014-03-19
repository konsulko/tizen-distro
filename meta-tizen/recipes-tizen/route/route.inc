DESCRIPTION = "A Location Route library in Tizen Native API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "API/C API"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by capi-location-route 
PROVIDES += "capi-location-route"
RPROVIDES_capi-location-route += "capi-location-route"

#PROVIDES by capi-location-route-devel 
PROVIDES += "capi-location-route-devel"
RPROVIDES_capi-location-route-devel += "capi-location-route-devel"
RPROVIDES_capi-location-route-devel += "capi-location-route-dev"

RDEPENDS = ""
#RDEPENDS of capi-location-route-devel (capi-location-${PN}-devel)
RDEPENDS_capi-location-${PN}-devel += "capi-location-route"


DEPENDS = ""
#DEPENDS of capi-location-route 
DEPENDS += "pkgconfig(location)"
DEPENDS += "cmake"
DEPENDS += "common"
DEPENDS += "pkgconfig(capi-location-manager)"
DEPENDS += "dlog"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-location-route.manifest .
 
 
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
 
 MAJORVER=`echo 0.1.4 | awk 'BEGIN {FS="."}{print $1}'`
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DFULLVER=0.1.4 -DMAJORVER=${MAJORVER}
 
 
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
PACKAGES += "capi-location-route"
PACKAGES += "capi-location-route-devel"

capi-location-route_files = ""
capi-location-route_files += "capi-location-route.manifest"
capi-location-route_files += "/usr/lib/libcapi-location-route.so.*"

capi-location-route-devel_files = ""
capi-location-route-devel_files += "capi-location-route.manifest"
capi-location-route-devel_files += "/usr/include/location/*.h"
capi-location-route-devel_files += "/usr/lib/pkgconfig/*.pc"
capi-location-route-devel_files += "/usr/lib/libcapi-location-route.so"

FILES_${PN} = "${capi-location-route_files}"
FILES_${PN}-devel = "${capi-location-route-devel_files}"

PKG_capi-location-route= "capi-location-route"
PKG_capi-location-route-devel= "capi-location-route-devel"

require route-extraconf.inc
