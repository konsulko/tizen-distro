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

#PROVIDES by Modello-Appmanager


RDEPENDS = ""
#RDEPENDS of Modello-Appmanager (${PN})
RDEPENDS_${PN} += "Modello-Common"


DEPENDS = ""
#DEPENDS of Modello-Appmanager
DEPENDS += "tizen-platform-config"
inherit pkgconfig
DEPENDS += "zip"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n Modello-Appmanager-0.0.2
 cp ${S}/packaging/Modello-Appmanager.manifest .
 
 
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
 zip -r ${D}/opt/usr/apps/.preinstallWidgets/Modello-Appmanager.wgt config.xml css AppManager_icon.png index.html js templates
 install -m 0644 AppManager_icon.png ${D}${prefix}/share/Modello/Common/icons
 
 
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " Modello-Appmanager "

Modello-Appmanager_files = ""
Modello-Appmanager_files += "/opt/usr/apps/.preinstallWidgets/Modello-Appmanager.wgt"
Modello-Appmanager_files += "${prefix}/share/Modello/Common/icons/AppManager_icon.png"
MANIFESTFILES_${PN} = "Modello-Appmanager.manifest"

FILES_${PN} = "${Modello-Appmanager_files}"

PKG_Modello-Appmanager= "Modello-Appmanager"

require Modello-Appmanager-extraconf.inc

