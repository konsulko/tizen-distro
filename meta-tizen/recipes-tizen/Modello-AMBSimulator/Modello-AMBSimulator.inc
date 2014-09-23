DESCRIPTION = "Pure html5 UI"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Automotive/Modello"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by Modello_AMBSimulator
PROVIDES += "Modello_AMBSimulator"


RDEPENDS = ""
#RDEPENDS of Modello_AMBSimulator (Modello_AMBSimulator)
RDEPENDS_Modello_AMBSimulator += "Modello_Common"


DEPENDS = ""
#DEPENDS of Modello_AMBSimulator
DEPENDS += "tizen-platform-config"
DEPENDS += "zip"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n Modello_AMBSimulator-0.0.2
 cp ${S}/packaging/Modello_AMBSimulator.manifest .
 
 
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
 mkdir -p ${D}%{TZ_SYS_APP_PREINSTALL}
 mkdir -p ${D}${prefix}/share/Modello/Common/icons
 zip -r ${D}%{TZ_SYS_APP_PREINSTALL}/Modello_AMBSimulator.wgt config.xml manifest.json css AMBSimulator_icon.png  index.html  js templates
 install -m 0644 AMBSimulator_icon.png ${D}${prefix}/share/Modello/Common/icons
 
 
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " Modello_AMBSimulator "

Modello_AMBSimulator_files = ""
Modello_AMBSimulator_files += "${prefix}/share/Modello/Common/icons/AMBSimulator_icon.png"
MANIFESTFILES_Modello_AMBSimulator = "Modello_AMBSimulator.manifest"

FILES_Modello_AMBSimulator = "${Modello_AMBSimulator_files}"

PKG_Modello_AMBSimulator= "Modello_AMBSimulator"

require Modello-AMBSimulator-extraconf.inc

