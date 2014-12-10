DESCRIPTION = "Crosswalk suite for Tizen Common"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Development/Testing"
LICENSE = "GPL-2.0"
PV = "1.1"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by common-crosswalk-suite


RDEPENDS = ""
#RDEPENDS of common-crosswalk-suite (${PN})
RDEPENDS_${PN} += "common-suite-launcher"
RDEPENDS_${PN} += "testkit-stub"
RDEPENDS_${PN} += "testkit-lite"


DEPENDS = ""

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/common-crosswalk-suite.manifest .
 
 
 
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
 
 install -d ${D}${prefix}/share/tests/common/common-crosswalk-suite
 install -m 0755 runtest ${D}${prefix}/share/tests/common/common-crosswalk-suite
 install -m 0644 *.xml ${D}${prefix}/share/tests/common/common-crosswalk-suite
 cp -r TESTDIR ${D}${prefix}/share/tests/common/common-crosswalk-suite
 
 
 
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " common-crosswalk-suite "

common-crosswalk-suite_files = ""
common-crosswalk-suite_files += "${prefix}/share/tests/common/common-crosswalk-suite"
MANIFESTFILES_${PN} = "common-crosswalk-suite.manifest"

FILES_${PN} = "${common-crosswalk-suite_files}"

PKG_common-crosswalk-suite= "common-crosswalk-suite"

require common-crosswalk-suite-extraconf.inc

