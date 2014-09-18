DESCRIPTION = "Sample homescreen and system controller"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Automotive/ICO Homescreen"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by ico-uxf-homescreen-system-controller-dev
PROVIDES += "ico-uxf-homescreen-system-controller-dev"


#PROVIDES by ico-uxf-homescreen-system-controller
PROVIDES += "ico-uxf-homescreen-system-controller"
# the PROVIDES rules is ignore "system-controller  "
PROVIDES += "system-controller"
RPROVIDES_ico-uxf-homescreen-system-controller += "system-controller"


#PROVIDES by ico-uxf-homescreen


RDEPENDS = ""
#RDEPENDS of ico-uxf-homescreen-system-controller-dev (${PN}-system-controller-dev)
RDEPENDS_${PN}-system-controller-dev += "edje"
RDEPENDS_${PN}-system-controller-dev += "ico-uxf-homescreen"
RDEPENDS_${PN}-system-controller-dev += "evas"
RDEPENDS_${PN}-system-controller-dev += "app-svc"
RDEPENDS_${PN}-system-controller-dev += "glib-2.0"
RDEPENDS_${PN}-system-controller-dev += "eina"
RDEPENDS_${PN}-system-controller-dev += "capi-base-common-dev"
RDEPENDS_${PN}-system-controller-dev += "ecore"

#RDEPENDS of ico-uxf-homescreen-system-controller (${PN}-system-controller)
RDEPENDS_${PN}-system-controller += "ico-uxf-utilities"
RDEPENDS_${PN}-system-controller += "ico-uxf-homescreen"
RDEPENDS_${PN}-system-controller += "weston-ivi-shell"
RDEPENDS_${PN}-system-controller += "weston"
RDEPENDS_${PN}-system-controller += "wayland-ivi-extension"
RDEPENDS_${PN}-system-controller += "ico-uxf-weston-plugin"

#RDEPENDS of ico-uxf-homescreen (${PN})
RDEPENDS_${PN} += "ico-uxf-utilities"
RDEPENDS_${PN} += "weston-ivi-shell"
RDEPENDS_${PN} += "weston"
RDEPENDS_${PN} += "wayland-ivi-extension"
RDEPENDS_${PN} += "system-controller"
RDEPENDS_${PN} += "ico-uxf-weston-plugin"


DEPENDS = ""
#DEPENDS of ico-uxf-homescreen
DEPENDS += "edje"
DEPENDS += "eina"
DEPENDS += "json-glib"
DEPENDS += "slp-pkgmgr"
DEPENDS += "wayland"
DEPENDS += "notification"
DEPENDS += "app-svc"
DEPENDS += "aul"
DEPENDS += "glib-2.0"
DEPENDS += "application"
DEPENDS += "boost"
DEPENDS += "ico-uxf-weston-plugin"
DEPENDS += "ico-uxf-utilities"
DEPENDS += "evas"
DEPENDS += "tizen-platform-config"
DEPENDS += "murphy"
DEPENDS += "bundle"
DEPENDS += "weston-ivi-shell"
DEPENDS += "libwebsockets"
DEPENDS += "ecore"
DEPENDS += "mesa"
DEPENDS += "dbus"
DEPENDS += "ail"
DEPENDS += "wayland-ivi-extension"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n ico-uxf-homescreen-0.9.22
 
 mkdir -p weston
 cp -av ${prefix}/share/genivi-shell/protocol/*.xml weston/
 
 ls weston/*.xml | while read protocol ; do
 
     ${prefix}/bin/wayland-scanner client-header \
         < "${protocol}" > "${protocol/.xml/}-client-protocol.h"
 
     ${prefix}/bin/wayland-scanner code \
         < "${protocol}" > "${protocol/.xml/.c}"
 
 done
 
 
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
  
  
   
  autotools_do_configure
  oe_runmake -j16
  
  
  
}
EXTRA_OECONF += ""

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
 
 cp tool/ico_clear_screen ${D}${prefix}/bin
 cp tool/ico_change_loginuser ${D}${prefix}/bin
 cp tool/notification/ico_del_notification ${D}${prefix}/bin
 cp tool/notification/ico_dump_notification ${D}${prefix}/bin
 cp tool/notification/ico_send_notification ${D}${prefix}/bin
 cp tool/notification/ico_send_notification2 ${D}${prefix}/bin
 
 
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
    # Update the app database.
    $D${prefix}/bin/pkginfo --imd $D${prefix}/share/packages/org.tizen.ico.homescreen.xml
    $D${prefix}/bin/pkginfo --imd $D${prefix}/share/packages/org.tizen.ico.statusbar.xml
    $D${prefix}/bin/pkginfo --imd $D${prefix}/share/packages/org.tizen.ico.system-controller.xml
    $D${prefix}/bin/pkginfo --imd $D${prefix}/share/packages/org.tizen.ico.onscreen.xml

}

pkg_prerm_${PN}() {
    #!/bin/sh -e

    # Update the app database.
    $D${prefix}/bin/pkginfo --rmd $D${prefix}/share/packages/org.tizen.ico.homescreen.xml
    $D${prefix}/bin/pkginfo --rmd $D${prefix}/share/packages/org.tizen.ico.statusbar.xml
    $D${prefix}/bin/pkginfo --rmd $D${prefix}/share/packages/org.tizen.ico.system-controller.xml
    $D${prefix}/bin/pkginfo --rmd $D${prefix}/share/packages/org.tizen.ico.onscreen.xml

}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
    rm -f $D${prefix}/share/applications/org.tizen.ico.homescreen.desktop
    rm -f $D${prefix}/share/applications/org.tizen.ico.statusbar.desktop
    rm -f $D${prefix}/share/applications/org.tizen.ico.onscreen.desktop
    rm -f $D${prefix}/share/applications/org.tizen.ico.system-controller.desktop

}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " ico-uxf-homescreen-system-controller-dev "
PACKAGES += " ico-uxf-homescreen-system-controller "
PACKAGES += " ico-uxf-homescreen "

ico-uxf-homescreen-system-controller-dev_files = ""
ico-uxf-homescreen-system-controller-dev_files += "${prefix}/include/ico-appfw/ico_syc_application.h"
ico-uxf-homescreen-system-controller-dev_files += "${prefix}/include/ico-appfw/ico_syc_appresctl.h"
ico-uxf-homescreen-system-controller-dev_files += "${prefix}/include/ico-appfw/ico_syc_common.h"
ico-uxf-homescreen-system-controller-dev_files += "${prefix}/include/ico-appfw/ico_syc_error.h"
ico-uxf-homescreen-system-controller-dev_files += "${prefix}/include/ico-appfw/ico_syc_inputctl.h"
ico-uxf-homescreen-system-controller-dev_files += "${prefix}/include/ico-appfw/ico_syc_private.h"
ico-uxf-homescreen-system-controller-dev_files += "${prefix}/include/ico-appfw/ico_syc_privilege.h"
ico-uxf-homescreen-system-controller-dev_files += "${prefix}/include/ico-appfw/ico_syc_type.h"
ico-uxf-homescreen-system-controller-dev_files += "${prefix}/include/ico-appfw/ico_syc_userctl.h"
ico-uxf-homescreen-system-controller-dev_files += "${prefix}/include/ico-appfw/ico_syc_winctl.h"
ico-uxf-homescreen-system-controller-dev_files += "${prefix}/include/ico-state-machine/CicoBlockParser.h"
ico-uxf-homescreen-system-controller-dev_files += "${prefix}/include/ico-state-machine/CicoEvent.h"
ico-uxf-homescreen-system-controller-dev_files += "${prefix}/include/ico-state-machine/CicoEventInfo.h"
ico-uxf-homescreen-system-controller-dev_files += "${prefix}/include/ico-state-machine/CicoFinalState.h"
ico-uxf-homescreen-system-controller-dev_files += "${prefix}/include/ico-state-machine/CicoHistoryState.h"
ico-uxf-homescreen-system-controller-dev_files += "${prefix}/include/ico-state-machine/CicoState.h"
ico-uxf-homescreen-system-controller-dev_files += "${prefix}/include/ico-state-machine/CicoStateAction.h"
ico-uxf-homescreen-system-controller-dev_files += "${prefix}/include/ico-state-machine/CicoStateCore.h"
ico-uxf-homescreen-system-controller-dev_files += "${prefix}/include/ico-state-machine/CicoStateMachine.h"
ico-uxf-homescreen-system-controller-dev_files += "${prefix}/include/ico-state-machine/CicoStateMachineCreator.h"
MANIFESTFILES_${PN}-system-controller-dev = "ico-uxf-homescreen.manifest"

ico-uxf-homescreen-system-controller_files = ""
ico-uxf-homescreen-system-controller_files += "/usr/share/packages/org.tizen.ico.system-controller.xml"
ico-uxf-homescreen-system-controller_files += "/usr/lib/systemd/user/ico-uxf-wait-launchpad-ready.path"
ico-uxf-homescreen-system-controller_files += "/usr/lib/systemd/user/weston.target.wants/ico-uxf-wait-launchpad-ready.path"
ico-uxf-homescreen-system-controller_files += "/usr/lib/systemd/user/ico-system-controller.service"
ico-uxf-homescreen-system-controller_files += "/usr/apps/org.tizen.ico.system-controller/bin"
ico-uxf-homescreen-system-controller_files += "/home/app/ico/defaultApps.info"
ico-uxf-homescreen-system-controller_files += "/home/app/ico"
MANIFESTFILES_${PN}-system-controller = "ico-uxf-homescreen.manifest"

ico-uxf-homescreen_files = ""
ico-uxf-homescreen_files += "${prefix}/apps/org.tizen.ico.homescreen"
ico-uxf-homescreen_files += "${prefix}/apps/org.tizen.ico.statusbar"
ico-uxf-homescreen_files += "${prefix}/apps/org.tizen.ico.onscreen"
ico-uxf-homescreen_files += "${prefix}/share/packages/org.tizen.ico.homescreen.xml"
ico-uxf-homescreen_files += "${prefix}/share/packages/org.tizen.ico.statusbar.xml"
ico-uxf-homescreen_files += "${prefix}/share/packages/org.tizen.ico.onscreen.xml"
ico-uxf-homescreen_files += "${prefix}/lib/libico-appfw.*"
ico-uxf-homescreen_files += "${prefix}/lib/libico-state-machine.*"
ico-uxf-homescreen_files += "${prefix}/bin/ico_clear_screen"
ico-uxf-homescreen_files += "${prefix}/bin/ico_change_loginuser"
ico-uxf-homescreen_files += "${prefix}/bin/ico_del_notification"
ico-uxf-homescreen_files += "${prefix}/bin/ico_dump_notification"
ico-uxf-homescreen_files += "${prefix}/bin/ico_send_notification"
ico-uxf-homescreen_files += "${prefix}/bin/ico_send_notification2"
ico-uxf-homescreen_files += "${prefix}/share/icons/default/small/org.tizen.ico.homescreen.png"
ico-uxf-homescreen_files += "${prefix}/share/icons/default/small/org.tizen.ico.statusbar.png"
ico-uxf-homescreen_files += "${prefix}/share/icons/default/small/org.tizen.ico.onscreen.png"
ico-uxf-homescreen_files += "/usr/apps/org.tizen.ico.system-controller/res/config"
MANIFESTFILES_${PN} = "ico-uxf-homescreen.manifest"

FILES_${PN}-system-controller-dev = "${ico-uxf-homescreen-system-controller-dev_files}"
FILES_${PN}-system-controller = "${ico-uxf-homescreen-system-controller_files}"
FILES_${PN} = "${ico-uxf-homescreen_files}"

PKG_ico-uxf-homescreen-system-controller-dev= "ico-uxf-homescreen-system-controller-dev"
PKG_ico-uxf-homescreen-system-controller= "ico-uxf-homescreen-system-controller"
PKG_ico-uxf-homescreen= "ico-uxf-homescreen"

require ico-uxf-homescreen-extraconf.inc

