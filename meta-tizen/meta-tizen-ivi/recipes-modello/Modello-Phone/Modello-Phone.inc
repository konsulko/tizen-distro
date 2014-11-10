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

#PROVIDES by Modello-Phone


RDEPENDS = ""
#RDEPENDS of Modello-Phone (${PN})
RDEPENDS_${PN} += "Modello-Common"
RDEPENDS_${PN} += "phoned"


DEPENDS = ""
#DEPENDS of Modello-Phone
DEPENDS += "tizen-platform-config"
inherit pkgconfig
DEPENDS += "zip"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n Modello-Phone-0.0.2
 cp ${S}/packaging/Modello-Phone.manifest .
 
 
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
 zip -r ${D}/opt/usr/apps/.preinstallWidgets/Modello-Phone.wgt config.xml css data Phone_icon.png index.html js templates
 install -m 0644 Phone_icon.png ${D}${prefix}/share/Modello/Common/icons
 
 
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " Modello-Phone "

Modello-Phone_files = ""
Modello-Phone_files += "/opt/usr/apps/.preinstallWidgets/Modello-Phone.wgt"
Modello-Phone_files += "${prefix}/share/Modello/Common/icons/Phone_icon.png"
MANIFESTFILES_${PN} = "Modello-Phone.manifest"

FILES_${PN} = "${Modello-Phone_files}"

PKG_Modello-Phone= "Modello-Phone"

require Modello-Phone-extraconf.inc

