DESCRIPTION = "Pure html5 UI"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Automotive/Modello"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by Modello_SDL
PROVIDES += "Modello_SDL"


RDEPENDS = ""
#RDEPENDS of Modello_SDL (Modello_SDL)
RDEPENDS_Modello_SDL += "Modello_Common"


DEPENDS = ""
#DEPENDS of Modello_SDL
DEPENDS += "tizen-platform-config"
DEPENDS += "zip"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n Modello_SDL-0.0.2
 cp ${S}/packaging/Modello_SDL.manifest .
 
 
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
 zip -r ${D}%{TZ_SYS_APP_PREINSTALL}/Modello_SDL.wgt app audio config.xml css ffw SmartDeviceLink_icon.png images index.html js lib locale
 install -m 0644 SmartDeviceLink_icon.png ${D}${prefix}/share/Modello/Common/icons
 
 
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " Modello_SDL "

Modello_SDL_files = ""
Modello_SDL_files += "${prefix}/share/Modello/Common/icons/SmartDeviceLink_icon.png"
MANIFESTFILES_Modello_SDL = "Modello_SDL.manifest"

FILES_Modello_SDL = "${Modello_SDL_files}"

PKG_Modello_SDL= "Modello_SDL"

require Modello-SDL-extraconf.inc

