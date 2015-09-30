DESCRIPTION = "Internet Browser based on Automotive Grade Linux application suite"
HOMEPAGE = "http://nohomepage.org"
SECTION = "OpenIVI"
LICENSE = "Apache-2.0"
PR = "r0"

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/Apache-2.0;md5=89aea4e17d99a7cacdbeed46a0096b10"

SRC_URI += "git://github.com/konsulko/openivi-media-manager-app.git;protocol=https;branch=master;tag=40a83c2ce2d340e7c0b9760eb8259ed90cd9fdc5"

BBCLASSEXTEND += " native "

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by openivi-media-manager-app


RDEPENDS = ""
#RDEPENDS of openivi-media-manager-app (${PN})
RDEPENDS_${PN} += "openivi-common-app"


DEPENDS = ""
#DEPENDS of openivi-media-manager-app
DEPENDS += "tizen-platform-config"
inherit pkgconfig
DEPENDS += "zip"
DEPENDS += "zip-native"
DEPENDS += "openivi-common-app"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n openivi-media-manager-app-0.0.2
 #cp ${S}/packaging/openivi-media-manager-app.manifest .
 
 
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
 zip -r ${D}/opt/usr/apps/.preinstallWidgets/openivi-media-manager-app.wgt css media-manager-artwork images icon.png index.html setup config.xml js manifest.json
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " openivi-media-manager-app "

openivi-media-manager-app_files = ""
openivi-media-manager-app_files += "/opt/usr/apps/.preinstallWidgets/openivi-media-manager-app.wgt"

FILES_${PN} = "${openivi-media-manager-app_files}"

PKG_openivi-media-manager-app= "openivi-media-manager-app"
