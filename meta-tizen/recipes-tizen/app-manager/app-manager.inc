DESCRIPTION = "Application Manager API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Application Framework/API"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by capi-appfw-app-manager


#PROVIDES by capi-appfw-app-manager-dev


RDEPENDS = ""
#RDEPENDS of capi-appfw-app-manager-dev (capi-appfw-${PN}-dev)
RDEPENDS_capi-appfw-${PN}-dev += "capi-appfw-app-manager"


DEPENDS = ""
#DEPENDS of capi-appfw-app-manager
DEPENDS_append_class-native = " cmake-native"
DEPENDS_append_class-target = " cmake-native"
DEPENDS += "slp-pkgmgr"
DEPENDS += "aul"
DEPENDS += "dlog"
DEPENDS += "glib-2.0"
DEPENDS += "ail"
DEPENDS += "pkgmgr-info"
DEPENDS += "vconf"
DEPENDS += "common"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-appfw-app-manager.manifest .
 
 
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
 
 MAJORVER=`echo 0.1.0 | awk 'BEGIN {FS="."}{print $1}'`
 
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
         ${EXTRA_OECMAKE} . -DFULLVER=0.1.0 -DMAJORVER=${MAJORVER}
 oe_runmake 
 
 
 
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
PACKAGES += " capi-appfw-app-manager "
PACKAGES += " capi-appfw-app-manager-dev "

capi-appfw-app-manager_files = ""
capi-appfw-app-manager_files += "${prefix}/lib/libcapi-appfw-app-manager.so.*"
MANIFESTFILES_capi-appfw-${PN} = "capi-appfw-app-manager.manifest"

capi-appfw-app-manager-dev_files = ""
capi-appfw-app-manager-dev_files += "${prefix}/include/appfw/*.h"
capi-appfw-app-manager-dev_files += "${prefix}/lib/libcapi-appfw-app-manager.so"
capi-appfw-app-manager-dev_files += "${prefix}/lib/pkgconfig/*.pc"
MANIFESTFILES_capi-appfw-${PN}-dev = "capi-appfw-app-manager.manifest"

FILES_capi-appfw-${PN} = "${capi-appfw-app-manager_files}"
FILES_capi-appfw-${PN}-dev = "${capi-appfw-app-manager-dev_files}"

PKG_capi-appfw-app-manager= "capi-appfw-app-manager"
PKG_capi-appfw-app-manager-dev= "capi-appfw-app-manager-dev"

require app-manager-extraconf.inc

