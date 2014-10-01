DESCRIPTION = "A proof of concept pure html5 UI"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Automotive/Modello"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by Modello-Homescreen


RDEPENDS = ""
#RDEPENDS of Modello-Homescreen (${PN})
RDEPENDS_${PN} += "Modello-Common"


DEPENDS = ""
#DEPENDS of Modello-Homescreen
DEPENDS += "zip"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n Modello-Homescreen-0.0.2
 cp ${S}/packaging/Modello-Homescreen.manifest .
 
 
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
 
 oe_runmake wgtPkg
 
 
 
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
     mkdir -p ${D}${systemd_unitdir}/user/weston.target.wants/
     install -m 755 systemd/modello_launcher.sh ${D}${prefix}/bin
     install -m 0644 systemd/Modello_Homescreen-launchpad-ready.path ${D}${systemd_unitdir}/user
     install -m 0644 systemd/Modello_Homescreen.service ${D}${systemd_unitdir}/user
     ln -sf ../Modello_Homescreen-launchpad-ready.path ${D}${systemd_unitdir}/user/weston.target.wants/
 
 
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " Modello-Homescreen "

Modello-Homescreen_files = ""
Modello-Homescreen_files += "/opt/usr/apps/.preinstallWidgets/Modello-Homescreen.wgt"
Modello-Homescreen_files += "/opt/usr/apps/_common/icons/Homescreen_icon.png"
Modello-Homescreen_files += "${systemd_unitdir}/user/Modello_Homescreen.service"
Modello-Homescreen_files += "${systemd_unitdir}/user/Modello_Homescreen-launchpad-ready.path"
Modello-Homescreen_files += "${prefix}/bin/modello_launcher.sh"
Modello-Homescreen_files += "${systemd_unitdir}/user/weston.target.wants"

FILES_${PN} = "${Modello-Homescreen_files}"

PKG_Modello-Homescreen= "Modello-Homescreen"

require Modello-Homescreen-extraconf.inc

