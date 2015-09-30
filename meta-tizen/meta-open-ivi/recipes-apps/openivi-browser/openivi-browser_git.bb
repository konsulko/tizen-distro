DESCRIPTION = "Internet Browser based on Automotive Grade Linux application suite"
HOMEPAGE = "http://nohomepage.org"
SECTION = "OpenIVI"
LICENSE = "Apache-2.0"
PR = "r0"

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/Apache-2.0;md5=89aea4e17d99a7cacdbeed46a0096b10"

SRC_URI += "git://github.com/konsulko/openivi-browser.git;protocol=https;branch=master;tag=285f80de04fc7500cbbeddd66097287fff92c06b"

BBCLASSEXTEND += " native "

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by openivi-browser


RDEPENDS = ""
#RDEPENDS of openivi-browser (${PN})
RDEPENDS_${PN} += "openivi-common-app"


DEPENDS = ""
#DEPENDS of openivi-browser
DEPENDS += "tizen-platform-config"
inherit pkgconfig
DEPENDS += "zip"
DEPENDS += "zip-native"
DEPENDS += "openivi-common-app"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n openivi-browser-0.0.2
 #cp ${S}/packaging/openivi-browser.manifest .
 
 
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
 zip -r ${D}/opt/usr/apps/.preinstallWidgets/openivi-browser.wgt css icon.png setup images js templates config.xml error.html index.html search.html warning.html manifest.json README.txt
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " openivi-browser "

openivi-browser_files = ""
openivi-browser_files += "/opt/usr/apps/.preinstallWidgets/openivi-browser.wgt"

FILES_${PN} = "${openivi-browser_files}"

PKG_openivi-browser= "openivi-browser"
