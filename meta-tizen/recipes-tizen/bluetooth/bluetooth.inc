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


#PROVIDES by capi-network-bluetooth


RDEPENDS = ""
#RDEPENDS of capi-network-bluetooth-dev (capi-network-${PN}-dev)
RDEPENDS_capi-network-${PN}-dev += "capi-network-bluetooth"


DEPENDS = ""
#DEPENDS of capi-network-bluetooth
DEPENDS_append_class-native = " cmake-native"
DEPENDS_append_class-target = " cmake-native"
DEPENDS += "dbus"
DEPENDS += "dlog"
DEPENDS += "glib-2.0"
DEPENDS += "common"
DEPENDS += "vconf"
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
 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" ; export CFLAGS ;
 CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ;
 FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ;
 LD_AS_NEEDED=1; export LD_AS_NEEDED ;
 
 MAJORVER=`echo 0.1.39 | awk 'BEGIN {FS="."}{print $1}'`
 
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
         -DBUILD_SHARED_LIBS:BOOL=ON . -DFULLVER=0.1.39 -DMAJORVER=${MAJORVER}
 
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

    ldconfig
}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    ldconfig
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " capi-network-bluetooth-dev "
PACKAGES += " capi-network-bluetooth "

capi-network-bluetooth-dev_files = ""
capi-network-bluetooth-dev_files += "capi-network-bluetooth-devel.manifest"
capi-network-bluetooth-dev_files += "${prefix}/include/network/bluetooth.h"
capi-network-bluetooth-dev_files += "${prefix}/lib/pkgconfig/capi-network-bluetooth.pc"
capi-network-bluetooth-dev_files += "${prefix}/lib/libcapi-network-bluetooth.so"

capi-network-bluetooth_files = ""
capi-network-bluetooth_files += "capi-network-bluetooth.manifest"
capi-network-bluetooth_files += "${prefix}/lib/libcapi-network-bluetooth.so.*"

FILES_capi-network-${PN}-dev = "${capi-network-bluetooth-dev_files}"
FILES_capi-network-${PN} = "${capi-network-bluetooth_files}"

PKG_capi-network-bluetooth-dev= "capi-network-bluetooth-dev"
PKG_capi-network-bluetooth= "capi-network-bluetooth"

require bluetooth-extraconf.inc

