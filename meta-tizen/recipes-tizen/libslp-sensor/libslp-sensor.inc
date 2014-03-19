DESCRIPTION = "Sensor framework client library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Sensor Framework"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by sensor 
PROVIDES += "sensor"
RPROVIDES_sensor += "sensor"

#PROVIDES by sensor-devel 
PROVIDES += "sensor-devel"
RPROVIDES_sensor-devel += "sensor-devel"
RPROVIDES_sensor-devel += "sensor-dev"

RDEPENDS = ""
#RDEPENDS of sensor-devel (sensor-devel)
RDEPENDS_sensor-devel += "sensor"


DEPENDS = ""
#DEPENDS of sensor 
DEPENDS += "vconf-keys-devel"
DEPENDS += "libsf-common"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "cmake"
DEPENDS += "pkgconfig(vconf)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n sensor-0.5.27
 cp ${S}/packaging/sensor.manifest ${S}/packaging/sensor-devel.manifest .
 
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake .
 
 
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
PACKAGES += "sensor"
PACKAGES += "sensor-devel"

sensor_files = ""
sensor_files += "sensor.manifest"
sensor_files += "/usr/lib/libsensor.so.*"

sensor-devel_files = ""
sensor-devel_files += "sensor-devel.manifest"
sensor-devel_files += "/usr/include/sensor/*.h"
sensor-devel_files += "/usr/lib/libsensor.so"
sensor-devel_files += "/usr/lib/pkgconfig/sensor.pc"

FILES_${PN} = "${sensor_files}"
FILES_${PN}-devel = "${sensor-devel_files}"

PKG_sensor= "sensor"
PKG_sensor-devel= "sensor-devel"

require libslp-sensor-extraconf.inc
