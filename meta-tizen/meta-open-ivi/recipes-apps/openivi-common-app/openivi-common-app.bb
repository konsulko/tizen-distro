DESCRIPTION = "HTML5 UI"
HOMEPAGE = "http://nohomepage.org"
SECTION = "OpenIVI"
LICENSE = "Apache-2.0"
PR = "r0"

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/Apache-2.0;md5=89aea4e17d99a7cacdbeed46a0096b10"

SRC_URI += "git://github.com/konsulko/openivi-common-app.git;protocol=https;branch=master;tag=659edc93478e22284613e544d91b7079c91f7e23"

BBCLASSEXTEND += " native "

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by openivi-common-app


RDEPENDS = ""

DEPENDS = ""
#DEPENDS of openivi-common-app
DEPENDS_append_class-native = " fdupes-native"
DEPENDS_append_class-target = " fdupes-native"

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " openivi-common-app "

openivi-common-app_files = ""
openivi-common-app_files += "${prefix}/share/openivi/Common/js"
openivi-common-app_files += "${prefix}/share/openivi/Common/css"
openivi-common-app_files += "${prefix}/share/openivi/Common/components"
openivi-common-app_files += "${prefix}/share/openivi/Common/fonts"
openivi-common-app_files += "${prefix}/share/openivi/Common/images"
openivi-common-app_files += "${prefix}/share/openivi/Common/json"

MANIFESTFILES_${PN} = "openivi-common-app.manifest"

FILES_${PN} = "${openivi-common-app_files}"

PKG_openivi-common-app= "openivi-common-app"

do_prep() {
}

do_configure() {
}

do_compile() {
 cd ${S}
}

do_install() {
 rm -rf ${D}
 mkdir -p ${D}
 
 mkdir -p ${D}${prefix}/share/openivi/Common/
 cp -r css ${D}${prefix}/share/openivi/Common/
 cp -r js ${D}${prefix}/share/openivi/Common/
 cp -r components ${D}${prefix}/share/openivi/Common/
 cp -r fonts ${D}${prefix}/share/openivi/Common/
 cp -r images ${D}${prefix}/share/openivi/Common/
 cp -r json ${D}${prefix}/share/openivi/Common/
}
