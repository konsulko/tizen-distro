DESCRIPTION = "Network Bluetooth Framework"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Connectivity/API"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by capi-network-bluetooth-dev
PROVIDES += "capi-network-bluetooth-dev"


#PROVIDES by capi-network-bluetooth
PROVIDES += "capi-network-bluetooth"


RDEPENDS = ""
#RDEPENDS of capi-network-bluetooth-dev (capi-network-${PN}-dev)
RDEPENDS_capi-network-${PN}-dev += "capi-network-bluetooth"


DEPENDS = ""
#DEPENDS of capi-network-bluetooth
inherit tizen_cmake
DEPENDS += "dlog"
DEPENDS += "glib-2.0"
DEPENDS += "common"
DEPENDS += "vconf"
DEPENDS += "dbus-glib"
DEPENDS += "bluetooth-frwk"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-network-bluetooth.manifest ${S}/packaging/capi-network-bluetooth-devel.manifest .
 
 
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
 
 MAJORVER=`echo 0.1.39 | awk 'BEGIN {FS="."}{print $1}'`
 
   cmake \
         -DCMAKE_VERBOSE_MAKEFILE=ON \
         -DCMAKE_INSTALL_PREFIX:PATH=${prefix} \
         -DCMAKE_INSTALL_LIBDIR:PATH=${prefix}/lib \
         -DINCLUDE_INSTALL_DIR:PATH=${prefix}/include \
         -DLIB_INSTALL_DIR:PATH=${prefix}/lib \
         -DSYSCONF_INSTALL_DIR:PATH=${sysconfdir} \
         -DSHARE_INSTALL_PREFIX:PATH=${prefix}/share \
         -DCMAKE_SKIP_RPATH:BOOL=ON \
         -DBUILD_SHARED_LIBS:BOOL=ON \
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake \
         ${EXTRA_OECMAKE} . -DFULLVER=0.1.39 -DMAJORVER=${MAJORVER}
 
 make -j16
 
 
 
}

do_install() {
 export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 
 
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " capi-network-bluetooth-dev "
PACKAGES += " capi-network-bluetooth "

capi-network-bluetooth-dev_files = ""
capi-network-bluetooth-dev_files += "${prefix}/include/network/bluetooth.h"
capi-network-bluetooth-dev_files += "${prefix}/lib/pkgconfig/capi-network-bluetooth.pc"
capi-network-bluetooth-dev_files += "${prefix}/lib/libcapi-network-bluetooth.so"
MANIFESTFILES_capi-network-${PN}-dev = "capi-network-bluetooth-devel.manifest"

capi-network-bluetooth_files = ""
capi-network-bluetooth_files += "${prefix}/lib/libcapi-network-bluetooth.so.*"
MANIFESTFILES_capi-network-${PN} = "capi-network-bluetooth.manifest"

FILES_capi-network-${PN}-dev = "${capi-network-bluetooth-dev_files}"
FILES_capi-network-${PN} = "${capi-network-bluetooth_files}"

PKG_capi-network-bluetooth-dev= "capi-network-bluetooth-dev"
PKG_capi-network-bluetooth= "capi-network-bluetooth"

require bluetooth-extraconf.inc

