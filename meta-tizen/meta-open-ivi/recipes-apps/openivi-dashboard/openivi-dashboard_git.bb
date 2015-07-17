DESCRIPTION = "HTML5 Dashboard app based on Automotive Grade Linux application suite"
HOMEPAGE = "http://nohomepage.org"
SECTION = "OpenIVI"
LICENSE = "Apache-2.0"
PR = "r0"

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/Apache-2.0;md5=89aea4e17d99a7cacdbeed46a0096b10"

SRC_URI += "git://github.com/konsulko/openivi-dashboard.git;protocol=https;branch=master;tag=720b0fb5d1588e6a0986e13c4e2ad96e16e6be01"

BBCLASSEXTEND += " native "

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by openivi-dashboard


RDEPENDS = ""
#RDEPENDS of openivi-dashboard (${PN})
RDEPENDS_${PN} += "openivi-common-app"


DEPENDS = ""
#DEPENDS of openivi-dashboard
DEPENDS += "tizen-platform-config"
inherit pkgconfig
DEPENDS += "zip"
DEPENDS += "zip-native"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n openivi-dashboard-0.0.2
 #cp ${S}/packaging/openivi-dashboard.manifest .
 
 
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
 
 #empty
 
 
 
}

do_install() {
 export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 mkdir -p ${D}/opt/usr/apps/.preinstallWidgets
 mkdir -p ${D}${prefix}/share/openivi/Common/icons
 zip -r ${D}/opt/usr/apps/.preinstallWidgets/openivi-dashboard.wgt css icon.png index.html images setup config.xml js manifest.json README.txt
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " openivi-dashboard "

openivi-dashboard_files = ""
openivi-dashboard_files += "/opt/usr/apps/.preinstallWidgets/openivi-dashboard.wgt"

FILES_${PN} = "${openivi-dashboard_files}"

PKG_openivi-dashboard= "openivi-dashboard"
