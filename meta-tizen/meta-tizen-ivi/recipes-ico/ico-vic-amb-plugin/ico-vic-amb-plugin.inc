DESCRIPTION = "Automotive Message Broker is a vehicle network abstraction system."
HOMEPAGE = "http://nohomepage.org"
SECTION = "System Environment/Daemons"
LICENSE = "LGPL v2.1"
PV = "0.9.5"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by ico-vic-amb-plugin


RDEPENDS = ""
#RDEPENDS of ico-vic-amb-plugin (${PN})
RDEPENDS_${PN} += "libjson"
RDEPENDS_${PN} += "ico-uxf-utilities"
RDEPENDS_${PN} += "glibc"


DEPENDS = ""
#DEPENDS of ico-vic-amb-plugin
DEPENDS += "ico-uxf-utilities"
inherit tizen_cmake
DEPENDS += "json-c"
inherit pkgconfig
DEPENDS += "app-core"
DEPENDS += "automotive-message-broker"
DEPENDS += "elementary"
DEPENDS += "boost"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n ico-vic-amb-plugin-0.9.5
 
 
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
         ${EXTRA_OECMAKE}
 
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
 
 rm -rf ${D}
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 mkdir -p ${D}/${sysconfdir}/ambd
 mkdir -p ${D}/usr/bin
 cp src/AMBformat.conf ${D}/${sysconfdir}/ambd/
 cp tool/ico_set_vehicleinfo ${D}/usr/bin/ico_set_vehicleinfo
 
 
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
PACKAGES += " ico-vic-amb-plugin "

ico-vic-amb-plugin_files = ""
ico-vic-amb-plugin_files += "${prefix}/lib/automotive-message-broker/*.so"
ico-vic-amb-plugin_files += "${sysconfdir}/ambd/AMBformat.conf"
ico-vic-amb-plugin_files += "/usr/share/doc/automotive-message-broker/ico-vic-amb-plugin/README"
ico-vic-amb-plugin_files += "/usr/bin/ico_set_vehicleinfo"
MANIFESTFILES_${PN} = "ico-vic-amb-plugin.manifest"

FILES_${PN} = "${ico-vic-amb-plugin_files}"

PKG_ico-vic-amb-plugin= "ico-vic-amb-plugin"

require ico-vic-amb-plugin-extraconf.inc

