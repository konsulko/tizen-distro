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

#PROVIDES by Modello-Dashboard


RDEPENDS = ""
#RDEPENDS of Modello-Dashboard (${PN})
RDEPENDS_${PN} += "Modello-Common"


DEPENDS = ""
#DEPENDS of Modello-Dashboard
DEPENDS += "tizen-platform-config"
inherit pkgconfig
DEPENDS += "zip"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n Modello-Dashboard-0.0.2
 cp ${S}/packaging/Modello-Dashboard.manifest .
 
 
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
 zip -r ${D}/opt/usr/apps/.preinstallWidgets/Modello-Dashboard.wgt components config.xml css Dashboard_icon.png index.html js
 install -m 0644 Dashboard_icon.png ${D}${prefix}/share/Modello/Common/icons
 
 
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " Modello-Dashboard "

Modello-Dashboard_files = ""
Modello-Dashboard_files += "/opt/usr/apps/.preinstallWidgets/Modello-Dashboard.wgt"
Modello-Dashboard_files += "${prefix}/share/Modello/Common/icons/Dashboard_icon.png"
MANIFESTFILES_${PN} = "Modello-Dashboard.manifest"

FILES_${PN} = "${Modello-Dashboard_files}"

PKG_Modello-Dashboard= "Modello-Dashboard"

require Modello-Dashboard-extraconf.inc

