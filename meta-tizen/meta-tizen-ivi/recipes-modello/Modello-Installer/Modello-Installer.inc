DESCRIPTION = "Installer for Modello"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Automotive/Modello"
LICENSE = "Apache-2.0"
PV = "0.0.2"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by Modello-Installer-xwalk
PROVIDES += "Modello-Installer-xwalk"


#PROVIDES by Modello-Installer-wrt
PROVIDES += "Modello-Installer-wrt"


#PROVIDES by Modello-Installer


RDEPENDS = ""
#RDEPENDS of Modello-Installer-xwalk (${PN}-xwalk)
RDEPENDS_${PN}-xwalk += "Modello-SDL"
RDEPENDS_${PN}-xwalk += "Modello-Dashboard"
RDEPENDS_${PN}-xwalk += "Modello-Homescreen"
RDEPENDS_${PN}-xwalk += "tizen-platform-config"
RDEPENDS_${PN}-xwalk += "Modello-Nav"
RDEPENDS_${PN}-xwalk += "Modello-Appmanager"
RDEPENDS_${PN}-xwalk += "Modello-Phone"
RDEPENDS_${PN}-xwalk += "Modello-Common"
RDEPENDS_${PN}-xwalk += "Modello-AMBSimulator"
RDEPENDS_${PN}-xwalk += "crosswalk"
RDEPENDS_${PN}-xwalk += "Modello-Hvac"
RDEPENDS_${PN}-xwalk += "Modello-Multimediaplayer"

#RDEPENDS of Modello-Installer-wrt (${PN}-wrt)
RDEPENDS_${PN}-wrt += "wrt-installer"


DEPENDS = ""

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n Modello-Installer-0.0.2
 cp ${S}/packaging/Modello-Installer.manifest .
 
 
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
 
 
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    source $D${sysconfdir}/tizen-platform.conf
    for list in $(find $TZ_SYS_APP_PREINSTALL -name "Modello*")
    do
    #wrt-installer requires you be root to install files
            wrt-installer -i $list
    done
    for list2 in $(ls -d /opt/usr/apps/*/)
    do
            mkdir -p "$list2/css"
            mkdir -p "$list2/js"
            cp -r $D${prefix}/share/Modello/Common/js/services "$list2/res/wgt/js/"
            cp -r $D${prefix}/share/Modello/Common/css/* "$list2/res/wgt/css/"
    done

}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    source $D${sysconfdir}/tizen-platform.conf
    export DBUS_SESSION_BUS_ADDRESS="unix:path=/run/user/5000/dbus/user_bus_socket"
    for list in $(find $TZ_SYS_APP_PREINSTALL -name "Modello*")
    do
    	#XWalk requires you not be root to install files
    	echo "Installing $list"
    	su app -c "pkgcmd -q -i -t wgt -p $list"
    done
    for list2 in $(ls -d $TZ_SYS_HOME/app/.config/xwalk-service/applications/*/)
    do
            su app -c "mkdir -p '$list2/css'"
            su app -c "mkdir -p '$list2/js'"
            su app -c "cp -r $D${prefix}/share/Modello/Common/js/services '$list2/js/'"
            su app -c "cp -r $D${prefix}/share/Modello/Common/css/* '$list2/css/'"
            su app -c "cp -r $D${prefix}/share/Modello/Common/icons '$list2/'"
    done

}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    source $D${sysconfdir}/tizen-platform.conf
    export DBUS_SESSION_BUS_ADDRESS="unix:path=/run/user/5000/dbus/user_bus_socket"
    for list3 in $(su app -c "xwalkctl" | grep Modello | cut -c 1-10)
    do
    	echo "Uninstalling $list3"
    	su app -c "pkgcmd -q -u -n $list3"
    done

}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " Modello-Installer-xwalk "
PACKAGES += " Modello-Installer-wrt "

Modello-Installer-xwalk_files = ""
MANIFESTFILES_${PN}-xwalk = "Modello-Installer.manifest"

Modello-Installer-wrt_files = ""
MANIFESTFILES_${PN}-wrt = "Modello-Installer.manifest"

FILES_${PN}-xwalk = "${Modello-Installer-xwalk_files}"
FILES_${PN}-wrt = "${Modello-Installer-wrt_files}"

PKG_Modello-Installer-xwalk= "Modello-Installer-xwalk"
PKG_Modello-Installer-wrt= "Modello-Installer-wrt"

require Modello-Installer-extraconf.inc

