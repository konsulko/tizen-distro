DESCRIPTION = "Pure html5 UI"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Automotive/Modello"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by Modello_Multimediaplayer
PROVIDES += "Modello_Multimediaplayer"


RDEPENDS = ""
#RDEPENDS of Modello_Multimediaplayer (Modello_Multimediaplayer)
RDEPENDS_Modello_Multimediaplayer += "Modello_Common"


DEPENDS = ""
#DEPENDS of Modello_Multimediaplayer
DEPENDS += "tizen-platform-config"
DEPENDS += "zip"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n Modello_Multimediaplayer-0.0.2
 cp ${S}/packaging/Modello_Multimediaplayer.manifest .
 
 
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
 zip -r ${D}%{TZ_SYS_APP_PREINSTALL}/Modello_Multimediaplayer.wgt components config.xml css MultimediaPlayer_icon.png images index.html js
 install -m 0644 MultimediaPlayer_icon.png ${D}${prefix}/share/Modello/Common/icons
 
 
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " Modello_Multimediaplayer "

Modello_Multimediaplayer_files = ""
Modello_Multimediaplayer_files += "${prefix}/share/Modello/Common/icons/MultimediaPlayer_icon.png"
MANIFESTFILES_Modello_Multimediaplayer = "Modello_Multimediaplayer.manifest"

FILES_Modello_Multimediaplayer = "${Modello_Multimediaplayer_files}"

PKG_Modello_Multimediaplayer= "Modello_Multimediaplayer"

require Modello-Multimediaplayer-extraconf.inc

