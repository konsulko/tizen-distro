DESCRIPTION = "Sanity suite for Tizen IVI"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Development/Testing"
LICENSE = "GPL-2.0"
PV = "1.1"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by ivi-sanity-suite-GUI
PROVIDES += "ivi-sanity-suite-GUI"


#PROVIDES by ivi-sanity-suite


RDEPENDS = ""
#RDEPENDS of ivi-sanity-suite-GUI (${PN}-GUI)
RDEPENDS_${PN}-GUI += "testkit-lite"
RDEPENDS_${PN}-GUI += "fMBT"

#RDEPENDS of ivi-sanity-suite (${PN})
RDEPENDS_${PN} += "common-suite-launcher"
RDEPENDS_${PN} += "testkit-lite"


DEPENDS = ""

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/ivi-sanity-suite.manifest .
 
 
 
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
 
 install -d ${D}${prefix}/share/tests/pc/ivi-sanity-suite
 install -m 0755 runtest ${D}${prefix}/share/tests/pc/ivi-sanity-suite
 install -m 0755 process_check/prs_checker ${D}${prefix}/share/tests/pc/ivi-sanity-suite
 install -m 0644 process_check/testkit.xml ${D}${prefix}/share/tests/pc/ivi-sanity-suite
 install -m 0644 LICENSE ${D}${prefix}/share/tests/pc/ivi-sanity-suite
 install -m 0644 process_check/README ${D}${prefix}/share/tests/pc/ivi-sanity-suite
 
 install -d ${D}${prefix}/share/tests/ivi/ivi-sanity-suite/GUI
 install -m 0755 GUI/runtest.sh ${D}${prefix}/share/tests/ivi/ivi-sanity-suite/GUI
 install -m 0755 GUI/ivi_apps.py ${D}${prefix}/share/tests/ivi/ivi-sanity-suite/GUI
 install -m 0755 GUI/ivi_tests.py ${D}${prefix}/share/tests/ivi/ivi-sanity-suite/GUI
 install -m 0644 GUI/testkit.xml ${D}${prefix}/share/tests/ivi/ivi-sanity-suite/GUI
 install -m 0644 GUI/README ${D}${prefix}/share/tests/ivi/ivi-sanity-suite/GUI
 install -m 0644 LICENSE ${D}${prefix}/share/tests/ivi/ivi-sanity-suite/GUI
 cp -r GUI/ivi-tests_pics ${D}${prefix}/share/tests/ivi/ivi-sanity-suite/GUI
 
 
 
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " ivi-sanity-suite-GUI "
PACKAGES += " ivi-sanity-suite "

ivi-sanity-suite-GUI_files = ""
ivi-sanity-suite-GUI_files += "${prefix}/share/tests/ivi/ivi-sanity-suite/GUI"

ivi-sanity-suite_files = ""
ivi-sanity-suite_files += "${prefix}/share/tests/ivi/ivi-sanity-suite/runtest"
ivi-sanity-suite_files += "${prefix}/share/tests/ivi/ivi-sanity-suite/prs_checker"
ivi-sanity-suite_files += "${prefix}/share/tests/ivi/ivi-sanity-suite/testkit.xml"
ivi-sanity-suite_files += "${prefix}/share/tests/ivi/ivi-sanity-suite/LICENSE"
ivi-sanity-suite_files += "${prefix}/share/tests/ivi/ivi-sanity-suite/README"
MANIFESTFILES_${PN} = "ivi-sanity-suite.manifest"

FILES_${PN}-GUI = "${ivi-sanity-suite-GUI_files}"
FILES_${PN} = "${ivi-sanity-suite_files}"

PKG_ivi-sanity-suite-GUI= "ivi-sanity-suite-GUI"
PKG_ivi-sanity-suite= "ivi-sanity-suite"

require ivi-sanity-suite-extraconf.inc

