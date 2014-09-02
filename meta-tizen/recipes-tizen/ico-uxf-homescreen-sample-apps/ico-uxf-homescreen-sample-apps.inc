DESCRIPTION = "HomeScreen sample application"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Utilities"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by ico-uxf-homescreen-sample-apps


RDEPENDS = ""
#RDEPENDS of ico-uxf-homescreen-sample-apps (${PN})
RDEPENDS_${PN} += "ico-uxf-utilities"
RDEPENDS_${PN} += "edbus"
RDEPENDS_${PN} += "ico-uxf-homescreen"
RDEPENDS_${PN} += "evas"
RDEPENDS_${PN} += "dbus"
RDEPENDS_${PN} += "capi-appfw-application"
RDEPENDS_${PN} += "weston-ivi-shell"
RDEPENDS_${PN} += "weston"
RDEPENDS_${PN} += "ico-vic-amb-plugin"
RDEPENDS_${PN} += "automotive-message-broker"
RDEPENDS_${PN} += "elementary"
RDEPENDS_${PN} += "ecore"
RDEPENDS_${PN} += "weekeyboard"
RDEPENDS_${PN} += "ico-uxf-weston-plugin"


DEPENDS = ""
#DEPENDS of ico-uxf-homescreen-sample-apps
DEPENDS += "edje"
DEPENDS += "ico-uxf-utilities"
DEPENDS += "edbus"
DEPENDS += "application"
DEPENDS += "evas"
DEPENDS += "dbus"
DEPENDS += "pulseaudio"
DEPENDS += "aul"
DEPENDS += "bundle"
DEPENDS += "glib-2.0"
DEPENDS += "eina"
DEPENDS += "elementary"
DEPENDS += "ecore"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n ico-uxf-homescreen-sample-apps-0.9.8
 
 
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
 
 # create tizen package metadata related directories
 mkdir -p ${D}${prefix}/share/packages/
 mkdir -p ${D}${prefix}/share/icons/default/small
 
 # configurations(ico-app-soundsample)
 
 mkdir -p ${D}/usr/apps/org.tizen.ico.app-soundsample/bin/
 mkdir -p ${D}/usr/apps/org.tizen.ico.app-soundsample/sounds/
 mkdir -p ${D}/usr/apps/org.tizen.ico.app-soundsample/res/icons/default/small/
 mkdir -p ${D}/usr/apps/org.tizen.ico.app-soundsample/res/images/
 install -m 0644 ico-app-soundsample/soundsample_config.txt ${D}/usr/apps/org.tizen.ico.app-soundsample/res/
 install -m 0644 ico-app-soundsample/sound_bg.png ${D}/usr/apps/org.tizen.ico.app-soundsample/res/images/
 install -m 0644 ico-app-soundsample/org.tizen.ico.app-soundsample.png ${D}/usr/apps/org.tizen.ico.app-soundsample/res/icons/default/small/
 install -m 0644 ico-app-soundsample/musicbox.wav ${D}/usr/apps/org.tizen.ico.app-soundsample/sounds/
 install -m 0644 ico-app-soundsample/org.tizen.ico.app-soundsample.xml ${D}${prefix}/share/packages/
 
 # configurations(ico-app-vicsample)
 
 mkdir -p ${D}/usr/apps/org.tizen.ico.app-vicsample/bin/
 mkdir -p ${D}/usr/apps/org.tizen.ico.app-vicsample/res/icons/default/small/
 mkdir -p ${D}/usr/apps/org.tizen.ico.app-vicsample/res/images/
 install -m 0644 ico-app-vicsample/vicsample_config.txt ${D}/usr/apps/org.tizen.ico.app-vicsample/res/
 install -m 0644 ico-app-vicsample/vicinfo_bg.png ${D}/usr/apps/org.tizen.ico.app-vicsample/res/images/
 install -m 0644 ico-app-vicsample/org.tizen.ico.app-vicsample.png ${D}/usr/apps/org.tizen.ico.app-vicsample/res/icons/default/small/
 install -m 0644 ico-app-vicsample/org.tizen.ico.app-vicsample.xml ${D}${prefix}/share/packages/
 
 # configurations(ico-app-miscellaneous)
 # install tizen package metadata for weston-terminal
 install -m 0644 ico-app-miscellaneous/terminal.xml ${D}${prefix}/share/packages/
 
 # install browser package metadata for MiniBrowser
 mkdir -p ${D}${prefix}/bin
 install -m 0644 ico-app-miscellaneous/browser.xml ${D}${prefix}/share/packages/
 install -m 0644 ico-app-miscellaneous/browser.png ${D}${prefix}/share/icons/default/small/
 install -m 0755 ico-app-miscellaneous/browser ${D}${prefix}/bin
 
 # install tizen package metadata for weekeyboard
 install -m 0644 ico-app-miscellaneous/weekeyboard.xml ${D}${prefix}/share/packages/
 
 
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    [ "x\$D" == "x" ] && ldconfig
    # This icon exists in main weston package so we don't package it in.
    # Create a symbolic link to it instead.
    ln -sf $D${prefix}/share/weston/terminal.png $D${prefix}/share/icons/default/small/
    # Update the app database.
    $D${prefix}/bin/pkginfo --imd /usr/share/packages/org.tizen.ico.app-soundsample.xml
    $D${prefix}/bin/pkginfo --imd /usr/share/packages/org.tizen.ico.app-vicsample.xml
    $D${prefix}/bin/pkginfo --imd /usr/share/packages/browser.xml
    $D${prefix}/bin/pkginfo --imd /usr/share/packages/terminal.xml

}

pkg_prerm_${PN}() {
    #!/bin/sh -e

    # Update the app database.
    $D${prefix}/bin/pkginfo --rmd /usr/share/packages/org.tizen.ico.app-soundsample.xml
    $D${prefix}/bin/pkginfo --rmd /usr/share/packages/org.tizen.ico.app-vicsample.xml
    $D${prefix}/bin/pkginfo --rmd /usr/share/packages/browser.xml
    $D${prefix}/bin/pkginfo --rmd /usr/share/packages/terminal.xml

}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    [ "x\$D" == "x" ] && ldconfig
    rm -f /usr/share/applications/org.tizen.ico.app-soundsample.desktop
    rm -f /usr/share/applications/org.tizen.ico.app-vicsample.desktop
    rm -f /usr/share/applications/browser.desktop
    rm -f /usr/share/applications/terminal.desktop
    rm -f $D${prefix}/share/icons/default/small/terminal.png

}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " ico-uxf-homescreen-sample-apps "

ico-uxf-homescreen-sample-apps_files = ""
ico-uxf-homescreen-sample-apps_files += "/usr/apps/org.tizen.ico.app-soundsample/bin/ico-app-soundsample"
ico-uxf-homescreen-sample-apps_files += "/usr/apps/org.tizen.ico.app-soundsample/res/soundsample_config.txt"
ico-uxf-homescreen-sample-apps_files += "/usr/apps/org.tizen.ico.app-soundsample/res/images/sound_bg.png"
ico-uxf-homescreen-sample-apps_files += "/usr/apps/org.tizen.ico.app-soundsample/res/icons/default/small/org.tizen.ico.app-soundsample.png"
ico-uxf-homescreen-sample-apps_files += "/usr/apps/org.tizen.ico.app-soundsample/sounds/musicbox.wav"
ico-uxf-homescreen-sample-apps_files += "${prefix}/share/packages/org.tizen.ico.app-soundsample.xml"
ico-uxf-homescreen-sample-apps_files += "/usr/apps/org.tizen.ico.app-vicsample/bin/ico-app-vicsample"
ico-uxf-homescreen-sample-apps_files += "/usr/apps/org.tizen.ico.app-vicsample/res/vicsample_config.txt"
ico-uxf-homescreen-sample-apps_files += "/usr/apps/org.tizen.ico.app-vicsample/res/images/vicinfo_bg.png"
ico-uxf-homescreen-sample-apps_files += "/usr/apps/org.tizen.ico.app-vicsample/res/icons/default/small/org.tizen.ico.app-vicsample.png"
ico-uxf-homescreen-sample-apps_files += "/usr/share/packages/org.tizen.ico.app-vicsample.xml"
ico-uxf-homescreen-sample-apps_files += "${prefix}/bin/browser"
ico-uxf-homescreen-sample-apps_files += "${prefix}/share/packages/browser.xml"
ico-uxf-homescreen-sample-apps_files += "${prefix}/share/packages/terminal.xml"
ico-uxf-homescreen-sample-apps_files += "${prefix}/share/packages/weekeyboard.xml"
ico-uxf-homescreen-sample-apps_files += "${prefix}/share/icons/default/small/browser.png"
MANIFESTFILES_${PN} = "ico-uxf-homescreen-sample-apps.manifest"

FILES_${PN} = "${ico-uxf-homescreen-sample-apps_files}"

PKG_ico-uxf-homescreen-sample-apps= "ico-uxf-homescreen-sample-apps"

require ico-uxf-homescreen-sample-apps-extraconf.inc
