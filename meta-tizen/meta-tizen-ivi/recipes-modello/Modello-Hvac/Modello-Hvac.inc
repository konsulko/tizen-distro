DESCRIPTION = "Pure html5 UI"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Automotive/Modello"
LICENSE = "Apache-2.0"
PV = "0.0.3"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by Modello-Hvac


RDEPENDS = ""
#RDEPENDS of Modello-Hvac (${PN})
RDEPENDS_${PN} += "Modello-Common"


DEPENDS = ""
#DEPENDS of Modello-Hvac
DEPENDS += "tizen-platform-config"
inherit pkgconfig
DEPENDS += "zip"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n Modello-Hvac-0.0.3
 cp ${S}/packaging/Modello-Hvac.manifest .
 
 
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
 zip -r ${D}/opt/usr/apps/.preinstallWidgets/Modello-Hvac.wgt config.xml css HVAC_icon.png index.html js
 install -m 0644 HVAC_icon.png ${D}${prefix}/share/Modello/Common/icons
 
 
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " Modello-Hvac "

Modello-Hvac_files = ""
Modello-Hvac_files += "/opt/usr/apps/.preinstallWidgets/Modello-Hvac.wgt"
Modello-Hvac_files += "${prefix}/share/Modello/Common/icons/HVAC_icon.png"

FILES_${PN} = "${Modello-Hvac_files}"

PKG_Modello-Hvac= "Modello-Hvac"

require Modello-Hvac-extraconf.inc

