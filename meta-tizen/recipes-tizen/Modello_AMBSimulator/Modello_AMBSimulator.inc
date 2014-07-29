DESCRIPTION = "A proof of concept pure html5 UI"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Applications/System"
LICENSE = "Apache 2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by Modello_AMBSimulator


RDEPENDS = ""
#RDEPENDS of Modello_AMBSimulator (${PN})
RDEPENDS_${PN} += "Modello_Common"


DEPENDS = ""
#DEPENDS of Modello_AMBSimulator
DEPENDS += "zip"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n Modello_AMBSimulator-0.0.2
 
 
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
 
 
 make wgtPkg
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 rm -rf ${D}
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " Modello_AMBSimulator "

Modello_AMBSimulator_files = ""
Modello_AMBSimulator_files += "/opt/usr/apps/.preinstallWidgets/Modello_AMBSimulator.wgt"
Modello_AMBSimulator_files += "/opt/usr/apps/_common/icons/AMB_Simulator_icon.png"

FILES_${PN} = "${Modello_AMBSimulator_files}"

PKG_Modello_AMBSimulator= "Modello_AMBSimulator"

require Modello_AMBSimulator-extraconf.inc

