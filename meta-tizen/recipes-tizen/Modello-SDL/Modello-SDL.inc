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

#PROVIDES by Modello-SDL


RDEPENDS = ""
#RDEPENDS of Modello-SDL (${PN})
RDEPENDS_${PN} += "Modello-Common"


DEPENDS = ""
#DEPENDS of Modello-SDL
DEPENDS += "tizen-platform-config"
inherit pkgconfig
DEPENDS += "zip"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n Modello-SDL-0.0.2
 cp ${S}/packaging/Modello-SDL.manifest .
 
 
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
 zip -r ${D}/opt/usr/apps/.preinstallWidgets/Modello-SDL.wgt app audio config.xml css ffw SmartDeviceLink_icon.png images index.html js lib locale
 install -m 0644 SmartDeviceLink_icon.png ${D}${prefix}/share/Modello/Common/icons
 
 
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " Modello-SDL "

Modello-SDL_files = ""
Modello-SDL_files += "/opt/usr/apps/.preinstallWidgets/Modello-SDL.wgt"
Modello-SDL_files += "${prefix}/share/Modello/Common/icons/SmartDeviceLink_icon.png"
MANIFESTFILES_${PN} = "Modello-SDL.manifest"

FILES_${PN} = "${Modello-SDL_files}"

PKG_Modello-SDL= "Modello-SDL"

require Modello-SDL-extraconf.inc

