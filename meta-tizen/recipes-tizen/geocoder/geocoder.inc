DESCRIPTION = "A Geocoder library in Tizen Native API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by capi-location-geocoder 
PROVIDES += "capi-location-geocoder"
RPROVIDES_capi-location-geocoder += "capi-location-geocoder"

#PROVIDES by capi-location-geocoder-devel 
PROVIDES += "capi-location-geocoder-devel"
RPROVIDES_capi-location-geocoder-devel += "capi-location-geocoder-devel"
RPROVIDES_capi-location-geocoder-devel += "capi-location-geocoder-dev"

RDEPENDS = ""
#RDEPENDS of capi-location-geocoder-devel (capi-location-${PN}-devel)
RDEPENDS_capi-location-${PN}-devel += "capi-location-geocoder"


DEPENDS = ""
#DEPENDS of capi-location-geocoder 
DEPENDS += "pkgconfig(location)"
DEPENDS += "cmake"
DEPENDS += "common"
DEPENDS += "dlog"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-location-geocoder.manifest .
 
 
 
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
 
 MAJORVER=`echo 0.1.2 | awk 'BEGIN {FS="."}{print $1}'`
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DFULLVER=0.1.2 -DMAJORVER=${MAJORVER}
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
PACKAGES += "capi-location-geocoder"
PACKAGES += "capi-location-geocoder-devel"

capi-location-geocoder_files = ""
capi-location-geocoder_files += "capi-location-geocoder.manifest"
capi-location-geocoder_files += "/usr/lib/libcapi-location-geocoder.so*"
capi-location-geocoder_files += "capi-location-geocoder.manifest"

capi-location-geocoder-devel_files = ""
capi-location-geocoder-devel_files += "capi-location-geocoder.manifest"
capi-location-geocoder-devel_files += "/usr/include/location/geocoder.h"
capi-location-geocoder-devel_files += "/usr/lib/pkgconfig/*.pc"

FILES_${PN} = "${capi-location-geocoder_files}"
FILES_${PN}-devel = "${capi-location-geocoder-devel_files}"

PKG_capi-location-geocoder= "capi-location-geocoder"
PKG_capi-location-geocoder-devel= "capi-location-geocoder-devel"

require geocoder-extraconf.inc
