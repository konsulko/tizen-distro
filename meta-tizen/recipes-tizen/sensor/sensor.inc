DESCRIPTION = "A Sensor library in TIZEN C API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "framework/system"
LICENSE = "Apache 2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by capi-system-sensor-devel 
PROVIDES += "capi-system-sensor-devel"
RPROVIDES_capi-system-sensor-devel += "capi-system-sensor-devel"
RPROVIDES_capi-system-sensor-devel += "capi-system-sensor-dev"

#PROVIDES by capi-system-sensor 
PROVIDES += "capi-system-sensor"
RPROVIDES_capi-system-sensor += "capi-system-sensor"

RDEPENDS = ""
#RDEPENDS of capi-system-sensor-devel (capi-system-${PN}-devel)
RDEPENDS_capi-system-${PN}-devel += "capi-system-sensor"


DEPENDS = ""
#DEPENDS of capi-system-sensor 
DEPENDS += "cmake"
DEPENDS += "libslp-sensor"
DEPENDS += "dlog"
DEPENDS += "common"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-system-sensor.manifest .
 
 
 
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
 
 MAJORVER=`echo 0.1.17 | awk 'BEGIN {FS="."}{print $1}'`
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DFULLVER=0.1.17 -DMAJORVER=${MAJORVER}
 
 
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf ${D}
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 mkdir -p ${D}/usr/share/license
 cp LICENSE ${D}/usr/share/license/capi-system-sensor
 
 
}

PACKAGES = ""
PACKAGES += "capi-system-sensor-devel"
PACKAGES += "capi-system-sensor"

capi-system-sensor-devel_files = ""
capi-system-sensor-devel_files += "capi-system-sensor.manifest"
capi-system-sensor-devel_files += "/usr/include/system/sensors.h"
capi-system-sensor-devel_files += "/usr/lib/pkgconfig/*.pc"
capi-system-sensor-devel_files += "/usr/lib/libcapi-system-sensor.so"
capi-system-sensor-devel_files += "/usr/share/license/capi-system-sensor"

capi-system-sensor_files = ""
capi-system-sensor_files += "capi-system-sensor.manifest"
capi-system-sensor_files += "/usr/lib/libcapi-system-sensor.so.*"

FILES_${PN}-devel = "${capi-system-sensor-devel_files}"
FILES_${PN} = "${capi-system-sensor_files}"

PKG_capi-system-sensor-devel= "capi-system-sensor-devel"
PKG_capi-system-sensor= "capi-system-sensor"

require sensor-extraconf.inc
