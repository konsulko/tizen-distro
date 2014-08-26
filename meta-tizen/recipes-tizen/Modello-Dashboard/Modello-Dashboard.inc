DESCRIPTION = "A proof of concept pure html5 UI"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Applications/System"
LICENSE = "Apache 2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by Modello_Dashboard
PROVIDES += "Modello_Dashboard"


RDEPENDS = ""
#RDEPENDS of Modello_Dashboard (Modello_Dashboard)
RDEPENDS_Modello_Dashboard += "Modello_Common"


DEPENDS = ""
#DEPENDS of Modello_Dashboard
DEPENDS += "zip"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n Modello_Dashboard-0.0.2
 
 
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
 export RPM_BUILD_ROOT=${D}
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
PACKAGES += " Modello_Dashboard "

Modello_Dashboard_files = ""
Modello_Dashboard_files += "/opt/usr/apps/.preinstallWidgets/Modello_Dashboard.wgt"
Modello_Dashboard_files += "/opt/usr/apps/_common/icons/Dashboard_icon.png"

FILES_Modello_Dashboard = "${Modello_Dashboard_files}"

PKG_Modello_Dashboard= "Modello_Dashboard"

require Modello-Dashboard-extraconf.inc

