DESCRIPTION = "Feedback library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache-2.0"
PV = "0.1.3"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by libfeedback-dev
PROVIDES += "libfeedback-dev"


#PROVIDES by libsvi
PROVIDES += "libsvi"


#PROVIDES by libsvi-dev
PROVIDES += "libsvi-dev"


#PROVIDES by svi-data
PROVIDES += "svi-data"


#PROVIDES by libfeedback


RDEPENDS = ""
#RDEPENDS of libfeedback-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "libfeedback"

#RDEPENDS of libsvi (libsvi)
RDEPENDS_libsvi += "libfeedback"

#RDEPENDS of libfeedback (${PN})
RDEPENDS_${PN} += "glibc"

#RDEPENDS of libsvi-dev (libsvi-dev)
RDEPENDS_libsvi-dev += "libsvi"


DEPENDS = ""
#DEPENDS of libfeedback
DEPENDS += "libmm-sound"
inherit tizen_cmake
DEPENDS += "libxml2"
DEPENDS += "tizen-platform-config"
inherit pkgconfig
DEPENDS += "dlog"
DEPENDS += "glib-2.0"
DEPENDS += "system-server"
DEPENDS += "capi-base-common"
DEPENDS += "vconf"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q 
 
 
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
 
 cp ${S}/packaging/libsvi.manifest .
 cp ${S}/packaging/libfeedback.manifest .
 cp ${S}/packaging/svi-data.manifest .
 
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
         ${EXTRA_OECMAKE} .
 oe_runmake
 
 
 
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
 
 mkdir -p ${D}${prefix}/share/license
 cp LICENSE.APLv2 ${D}${prefix}/share/license/libfeedback
 
 
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postinst_libsvi() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postrm_svi-data() {
    #!/bin/sh -e

    rm -rf $D${prefix}/share/feedback/

}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postrm_libsvi() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " libfeedback-dev "
PACKAGES += " svi-data "
PACKAGES += " libfeedback "
PACKAGES += " libsvi-dev "
PACKAGES += " libsvi "

libfeedback-dev_files = ""
libfeedback-dev_files += "${prefix}/include/feedback/*.h"
libfeedback-dev_files += "${prefix}/lib/libfeedback.so"
libfeedback-dev_files += "${prefix}/lib/pkgconfig/feedback.pc"
MANIFESTFILES_${PN}-dev = "libfeedback.manifest"

svi-data_files = ""
svi-data_files += "${prefix}/share/feedback/*"
MANIFESTFILES_svi-data = "libfeedback.manifest"

libfeedback_files = ""
libfeedback_files += "${prefix}/lib/libfeedback.so.*"
libfeedback_files += "${prefix}/share/license/libfeedback"
MANIFESTFILES_${PN} = "libfeedback.manifest"

libsvi-dev_files = ""
libsvi-dev_files += "${prefix}/include/svi/*.h"
libsvi-dev_files += "${prefix}/lib/libsvi.so"
libsvi-dev_files += "${prefix}/lib/pkgconfig/svi.pc"
MANIFESTFILES_libsvi-dev = "libfeedback.manifest"

libsvi_files = ""
libsvi_files += "${prefix}/lib/libsvi.so.*"
MANIFESTFILES_libsvi = "libfeedback.manifest"

FILES_${PN}-dev = "${libfeedback-dev_files}"
FILES_svi-data = "${svi-data_files}"
FILES_${PN} = "${libfeedback_files}"
FILES_libsvi-dev = "${libsvi-dev_files}"
FILES_libsvi = "${libsvi_files}"

PKG_libfeedback-dev= "libfeedback-dev"
PKG_svi-data= "svi-data"
PKG_libfeedback= "libfeedback"
PKG_libsvi-dev= "libsvi-dev"
PKG_libsvi= "libsvi"

require libfeedback-extraconf.inc

