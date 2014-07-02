DESCRIPTION = "A Sensor library in TIZEN C API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "framework/system"
LICENSE = "Apache 2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by capi-system-sensor-dev


#PROVIDES by capi-system-sensor


RDEPENDS = ""
#RDEPENDS of capi-system-sensor-dev (capi-system-${PN}-dev)
RDEPENDS_capi-system-${PN}-dev += "capi-system-sensor"


DEPENDS = ""
#DEPENDS of capi-system-sensor
DEPENDS_append_class-native = " cmake-native"
DEPENDS_append_class-target = " cmake-native"
DEPENDS += "libslp-sensor"
DEPENDS += "dlog"
DEPENDS += "common"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-system-sensor.manifest .
 
 
 
}
do_patch_append() {
    bb.build.exec_func('do_prep', d)
}

do_configure() {
}

do_compile() {
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 LD_AS_NEEDED=1; export LD_AS_NEEDED ;
 
 MAJORVER=`echo 0.1.17 | awk 'BEGIN {FS="."}{print $1}'`
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export FFLAGS ; 
   cmake \
         -DCMAKE_VERBOSE_MAKEFILE=ON \
         -DCMAKE_INSTALL_PREFIX:PATH=${prefix} \
         -DCMAKE_INSTALL_LIBDIR:PATH=${prefix}/lib \
         -DINCLUDE_INSTALL_DIR:PATH=${prefix}/include \
         -DLIB_INSTALL_DIR:PATH=${prefix}/lib \
         -DSYSCONF_INSTALL_DIR:PATH=${sysconfdir} \
         -DSHARE_INSTALL_PREFIX:PATH=${prefix}/share \
         -DCMAKE_SKIP_RPATH:BOOL=ON \
         -DBUILD_SHARED_LIBS:BOOL=ON . -DFULLVER=0.1.17 -DMAJORVER=${MAJORVER}
 
 
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 rm -rf ${D}
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 mkdir -p ${D}/usr/share/license
 cp LICENSE ${D}/usr/share/license/capi-system-sensor
 
 
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    ldconfig
}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    ldconfig
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " capi-system-sensor-dev "
PACKAGES += " capi-system-sensor "

capi-system-sensor-dev_files = ""
capi-system-sensor-dev_files += "capi-system-sensor.manifest"
capi-system-sensor-dev_files += "${prefix}/include/system/sensors.h"
capi-system-sensor-dev_files += "${prefix}/lib/pkgconfig/*.pc"
capi-system-sensor-dev_files += "${prefix}/lib/libcapi-system-sensor.so"
capi-system-sensor-dev_files += "/usr/share/license/capi-system-sensor"

capi-system-sensor_files = ""
capi-system-sensor_files += "capi-system-sensor.manifest"
capi-system-sensor_files += "${prefix}/lib/libcapi-system-sensor.so.*"

FILES_capi-system-${PN}-dev = "${capi-system-sensor-dev_files}"
FILES_capi-system-${PN} = "${capi-system-sensor_files}"

PKG_capi-system-sensor-dev= "capi-system-sensor-dev"
PKG_capi-system-sensor= "capi-system-sensor"

require sensor-extraconf.inc

