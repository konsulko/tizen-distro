DESCRIPTION = "Pure html5 UI"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Automotive/Modello"
LICENSE = "Apache-2.0"
PV = "0.0.2"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by Modello-AMBSimulator


RDEPENDS = ""
#RDEPENDS of Modello-AMBSimulator (${PN})
RDEPENDS_${PN} += "Modello-Common"


DEPENDS = ""
#DEPENDS of Modello-AMBSimulator
DEPENDS += "tizen-platform-config"
inherit pkgconfig
DEPENDS += "zip"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n Modello-AMBSimulator-0.0.2
 cp ${S}/packaging/Modello-AMBSimulator.manifest .
 
 
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
 
 rm -rf ${D}
 mkdir -p ${D}/opt/usr/apps/.preinstallWidgets
 mkdir -p ${D}${prefix}/share/Modello/Common/icons
 zip -r ${D}/opt/usr/apps/.preinstallWidgets/Modello-AMBSimulator.wgt config.xml manifest.json css AMBSimulator_icon.png  index.html  js templates
 install -m 0644 AMBSimulator_icon.png ${D}${prefix}/share/Modello/Common/icons
 
 
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " Modello-AMBSimulator "

Modello-AMBSimulator_files = ""
Modello-AMBSimulator_files += "/opt/usr/apps/.preinstallWidgets/Modello-AMBSimulator.wgt"
Modello-AMBSimulator_files += "${prefix}/share/Modello/Common/icons/AMBSimulator_icon.png"
MANIFESTFILES_${PN} = "Modello-AMBSimulator.manifest"

FILES_${PN} = "${Modello-AMBSimulator_files}"

PKG_Modello-AMBSimulator= "Modello-AMBSimulator"

require Modello-AMBSimulator-extraconf.inc

