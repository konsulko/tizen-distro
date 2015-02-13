DESCRIPTION = "Graphics suite for Tizen Common"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Development/Testing"
LICENSE = "GPL-2.0"
PV = "1.1"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by common-graphics-suite


RDEPENDS = ""
#RDEPENDS of common-graphics-suite (${PN})
RDEPENDS_${PN} += "common-suite-launcher"
RDEPENDS_${PN} += "wayland-fits-master"
RDEPENDS_${PN} += "testkit-lite"


DEPENDS = ""

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/common-graphics-suite.manifest .
 
 
 
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
 
 install -d ${D}${prefix}/share/tests/common/common-graphics-suite
 install -m 0755 runtest ${D}${prefix}/share/tests/common/common-graphics-suite
 install -m 0644 *.xml ${D}${prefix}/share/tests/common/common-graphics-suite
 install -m 0644 LICENSE ${D}${prefix}/share/tests/common/common-graphics-suite
 cp -r TESTDIR ${D}${prefix}/share/tests/common/common-graphics-suite
 
 
 
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " common-graphics-suite "

common-graphics-suite_files = ""
common-graphics-suite_files += "${prefix}/share/tests/common/common-graphics-suite"
MANIFESTFILES_${PN} = "common-graphics-suite.manifest"

FILES_${PN} = "${common-graphics-suite_files}"

PKG_common-graphics-suite= "common-graphics-suite"

require common-graphics-suite-extraconf.inc

