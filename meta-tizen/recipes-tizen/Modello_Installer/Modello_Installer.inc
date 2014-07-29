DESCRIPTION = "Installer for Modello"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Base/Configuration"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by Modello_Installer


#PROVIDES by Modello_Installer-xwalk
PROVIDES += "Modello_Installer-xwalk"


#PROVIDES by Modello_Installer-wrt
PROVIDES += "Modello_Installer-wrt"


RDEPENDS = ""
#RDEPENDS of Modello_Installer-xwalk (${PN}-xwalk)
RDEPENDS_${PN}-xwalk += "Modello_AMBSimulator"
RDEPENDS_${PN}-xwalk += "Modello_Common"
RDEPENDS_${PN}-xwalk += "Modello_Appmanager"
RDEPENDS_${PN}-xwalk += "tizen-platform-config"
RDEPENDS_${PN}-xwalk += "Modello_Dashboard"
RDEPENDS_${PN}-xwalk += "Modello_Multimediaplayer"
RDEPENDS_${PN}-xwalk += "Modello_SDL"
RDEPENDS_${PN}-xwalk += "Modello_Phone"
RDEPENDS_${PN}-xwalk += "Modello_Homescreen"
RDEPENDS_${PN}-xwalk += "Modello_Nav"
RDEPENDS_${PN}-xwalk += "crosswalk"
RDEPENDS_${PN}-xwalk += "Modello_Hvac"

#RDEPENDS of Modello_Installer-wrt (${PN}-wrt)
RDEPENDS_${PN}-wrt += "wrt-installer"


DEPENDS = ""

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n Modello_Installer-0.0.2
 
 
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
 
 #build section
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
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
 
 
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    source ${sysconfdir}/tizen-platform.conf
    for list in $(find $TZ_SYS_APP_PREINSTALL -name "Modello*")
    do
    #wrt-installer requires you be root to install files
            wrt-installer -i $list
    done
    for list2 in $(ls -d /opt/usr/apps/*/)
    do
            mkdir -p "$list2/css"
            mkdir -p "$list2/js"
            cp -r /opt/usr/apps/_common/js/services "$list2/res/wgt/js/"
            cp -r /opt/usr/apps/_common/css/* "$list2/res/wgt/css/"
    done

}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    source ${sysconfdir}/tizen-platform.conf
    export DBUS_SESSION_BUS_ADDRESS="unix:path=/run/user/5000/dbus/user_bus_socket"
    for list in $(find $TZ_SYS_APP_PREINSTALL -name "Modello*")
    do
    #XWalk requires you not be root to install files
            echo "Installing $list"
            su app -c "xwalkctl -i $list"
    done
    for list2 in $(ls -d $TZ_SYS_HOME/app/.config/xwalk-service/applications/*/)
    do
            su app -c "mkdir -p '$list2/css'"
            su app -c "mkdir -p '$list2/js'"
            su app -c "cp -r /opt/usr/apps/_common/js/services '$list2/js/'"
            su app -c "cp -r /opt/usr/apps/_common/css/* '$list2/css/'"
            su app -c "cp -r /opt/usr/apps/_common/icons '$list2/'"
    done

}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    source ${sysconfdir}/tizen-platform.conf
    for list3 in $(su app -c "xwalkctl" | grep Modello | cut -c 1-32)
    do
            echo "Uninstalling $list3"
            su app -c "xwalkctl -u $list3"
    done

}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " Modello_Installer-xwalk "
PACKAGES += " Modello_Installer-wrt "

Modello_Installer-xwalk_files = ""

Modello_Installer-wrt_files = ""

FILES_${PN}-xwalk = "${Modello_Installer-xwalk_files}"
FILES_${PN}-wrt = "${Modello_Installer-wrt_files}"

PKG_Modello_Installer-xwalk= "Modello_Installer-xwalk"
PKG_Modello_Installer-wrt= "Modello_Installer-wrt"

require Modello_Installer-extraconf.inc

