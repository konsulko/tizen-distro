DESCRIPTION = "Network Wi-Fi library in TIZEN C API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Network"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by capi-network-wifi-dev
PROVIDES += "capi-network-wifi-dev"


#PROVIDES by capi-network-wifi
PROVIDES += "capi-network-wifi"


RDEPENDS = ""
#RDEPENDS of capi-network-wifi-dev (capi-network-${PN}-dev)
RDEPENDS_capi-network-${PN}-dev += "capi-network-wifi"


DEPENDS = ""
#DEPENDS of capi-network-wifi
DEPENDS_append_class-native = " cmake-native"
DEPENDS_append_class-target = " cmake-native"
DEPENDS += "dlog"
DEPENDS += "glib-2.0"
DEPENDS += "common"
DEPENDS += "vconf"
DEPENDS += "libnet-client"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-network-wifi.manifest .
 
 
 
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
 
 MAJORVER=`echo 0.1.2_18 | awk 'BEGIN {FS="."}{print $1}'`
 
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
         ${EXTRA_OECMAKE} . -DFULLVER=0.1.2_18 -DMAJORVER=${MAJORVER}
 
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
 
 #License
 mkdir -p ${D}${prefix}/share/license
 cp LICENSE.APLv2 ${D}${prefix}/share/license/capi-network-wifi
 
 
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    [ "x\$D" == "x" ] && ldconfig
}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    [ "x\$D" == "x" ] && ldconfig
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " capi-network-wifi-dev "
PACKAGES += " capi-network-wifi "

capi-network-wifi-dev_files = ""
capi-network-wifi-dev_files += "${prefix}/include/network/*.h"
capi-network-wifi-dev_files += "${prefix}/lib/pkgconfig/*.pc"
capi-network-wifi-dev_files += "${prefix}/lib/libcapi-network-wifi.so"
MANIFESTFILES_capi-network-${PN}-dev = "capi-network-wifi.manifest"

capi-network-wifi_files = ""
capi-network-wifi_files += "${prefix}/lib/libcapi-network-wifi.so.*"
capi-network-wifi_files += "${prefix}/share/license/capi-network-wifi"
MANIFESTFILES_capi-network-${PN} = "capi-network-wifi.manifest"

FILES_capi-network-${PN}-dev = "${capi-network-wifi-dev_files}"
FILES_capi-network-${PN} = "${capi-network-wifi_files}"

PKG_capi-network-wifi-dev= "capi-network-wifi-dev"
PKG_capi-network-wifi= "capi-network-wifi"

require wifi-extraconf.inc

