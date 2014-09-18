DESCRIPTION = "A proof of concept pure html5 UI"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Automotive/Modello"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by Modello_Homescreen
PROVIDES += "Modello_Homescreen"


RDEPENDS = ""
#RDEPENDS of Modello_Homescreen (Modello_Homescreen)
RDEPENDS_Modello_Homescreen += "Modello_Common"


DEPENDS = ""
#DEPENDS of Modello_Homescreen
DEPENDS += "zip"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n Modello_Homescreen-0.0.2
 
 
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
 
     
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
     mkdir -p ${D}${prefix}/bin
     mkdir -p ${D}/lib/systemd/user/weston.target.wants/
     install -m 755 systemd/modello_launcher.sh ${D}${prefix}/bin
     install -m 0644 systemd/Modello_Homescreen-launchpad-ready.path ${D}/lib/systemd/user
     install -m 0644 systemd/Modello_Homescreen.service ${D}/lib/systemd/user
     ln -sf ../Modello_Homescreen-launchpad-ready.path ${D}/lib/systemd/user/weston.target.wants/
 
 
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " Modello_Homescreen "

Modello_Homescreen_files = ""
Modello_Homescreen_files += "/opt/usr/apps/.preinstallWidgets/Modello_Homescreen.wgt"
Modello_Homescreen_files += "/opt/usr/apps/_common/icons/Homescreen_icon.png"
Modello_Homescreen_files += "/lib/systemd/user/Modello_Homescreen.service"
Modello_Homescreen_files += "/lib/systemd/user/Modello_Homescreen-launchpad-ready.path"
Modello_Homescreen_files += "${prefix}/bin/modello_launcher.sh"
Modello_Homescreen_files += "/lib/systemd/user/weston.target.wants"

FILES_Modello_Homescreen = "${Modello_Homescreen_files}"

PKG_Modello_Homescreen= "Modello_Homescreen"

require Modello-Homescreen-extraconf.inc

