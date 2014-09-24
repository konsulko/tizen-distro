DESCRIPTION = "Pure html5 UI"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Automotive/Modello"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by Modello_Appmanager
PROVIDES += "Modello_Appmanager"


RDEPENDS = ""
#RDEPENDS of Modello_Appmanager (Modello_Appmanager)
RDEPENDS_Modello_Appmanager += "Modello_Common"


DEPENDS = ""
#DEPENDS of Modello_Appmanager
DEPENDS += "tizen-platform-config"
DEPENDS += "zip"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n Modello_Appmanager-0.0.2
 cp ${S}/packaging/Modello_Appmanager.manifest .
 
 
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
 zip -r ${D}%{TZ_SYS_APP_PREINSTALL}/Modello_Appmanager.wgt config.xml css AppManager_icon.png index.html js templates
 install -m 0644 AppManager_icon.png ${D}${prefix}/share/Modello/Common/icons
 
 
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " Modello_Appmanager "

Modello_Appmanager_files = ""
Modello_Appmanager_files += "${prefix}/share/Modello/Common/icons/AppManager_icon.png"
MANIFESTFILES_Modello_Appmanager = "Modello_Appmanager.manifest"

FILES_Modello_Appmanager = "${Modello_Appmanager_files}"

PKG_Modello_Appmanager= "Modello_Appmanager"

require Modello-Appmanager-extraconf.inc

