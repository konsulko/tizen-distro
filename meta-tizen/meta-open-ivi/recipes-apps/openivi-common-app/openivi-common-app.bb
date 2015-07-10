DESCRIPTION = "HTML5 UI"
HOMEPAGE = "http://nohomepage.org"
SECTION = "OpenIVI"
LICENSE = "Apache-2.0"
PR = "r0"

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/Apache-2.0;md5=89aea4e17d99a7cacdbeed46a0096b10"

SRC_URI += "git://github.com/konsulko/openivi-common-app.git;branch=master;tag=f37ec40b5912df0b935306cc947ac0c5c2f00830"

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
MANIFESTFILES_${PN} = "openivi-common-app.manifest"

FILES_${PN} = "${openivi-common-app_files}"

PKG_openivi-common-app= "openivi-common-app"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n openivi-common-app-0.0.3
 #cp ${S}/packaging/openivi-common-app.manifest .
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
}

do_install() {
 export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 mkdir -p ${D}${prefix}/share/openivi/Common/
 cp -r css ${D}${prefix}/share/openivi/Common/
 cp -r js ${D}${prefix}/share/openivi/Common/
 
 #fdupes ${D}${prefix}/share
}
