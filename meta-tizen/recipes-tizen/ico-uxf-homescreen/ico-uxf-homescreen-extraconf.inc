do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n ico-uxf-homescreen-0.9.22
 cp ${S}/packaging/ico-uxf-homescreen.manifest .
}

do_compile_prepend()  {
 mkdir -p weston
 cp -av ${STAGING_DIR_TARGET}/usr/share/genivi-shell/protocol/*.xml weston/

 ls weston/*.xml | while read protocol ; do
     ${STAGING_BINDIR_NATIVE}/wayland-scanner client-header < "${protocol}" > "${protocol/.xml/}-client-protocol.h"
     ${STAGING_BINDIR_NATIVE}/wayland-scanner code < "${protocol}" > "${protocol/.xml/.c}"
 done

 find ${S} -name Makefile.am -exec sed -i "s@-I/usr/include/ico-util@-I${PKG_CONFIG_SYSROOT_DIR}/usr/include/ico-util@g" {} \;
 find ${S} -name Makefile.am -exec sed -i "s@-I/usr/include/ilm@-I${PKG_CONFIG_SYSROOT_DIR}/usr/include/ilm@g" {} \;
 find ${S} -name Makefile.am -exec sed -i "s@-I/usr/include/layermanager@-I${PKG_CONFIG_SYSROOT_DIR}/usr/include/layermanager@g" {} \;
 find ${S} -name Makefile.am -exec sed -i "s@-I/usr/include/ico-uxf-weston-plugin@-I${PKG_CONFIG_SYSROOT_DIR}/usr/include/ico-uxf-weston-plugin@g" {} \;
 
 sed -i "s@-I/usr/include/ico-util@-I${PKG_CONFIG_SYSROOT_DIR}/usr/include/ico-util@g" ${S}/configure.ac
}

do_install_append() {
    if ${@bb.utils.contains('SYS_CTLR_PROVIDER', 'ico-uxf-homescreen', 'false', 'true', d)}; then
      rm -f ${D}${prefix}/lib/systemd/user/ico-uxf-wait-launchpad-ready.path
      rm -fr ${D}${prefix}/lib/systemd/use
    fi
}

DEPENDS += "pkgmgr-native"
DEPENDS += "ail-native"

RDEPENDS_${PN} += "pkgmgr"
RDEPENDS_${PN} += "ail"

FILES_${PN} += "${datadir}/icons/default/small/org.tizen.ico.onscreen.png"
FILES_${PN} += "${datadir}/icons/default/small/org.tizen.ico.homescreen.png"
FILES_${PN} += "${datadir}/icons/default/small/org.tizen.ico.statusbar.png"

INSANE_SKIP_${PN} = "dev-so"
#FILES_${PN}-system-controller-dev += "${prefix}/lib/libico-state-machine.so"

FILES_${PN}-dbg += "${prefix}/apps/org.tizen.ico.onscreen/bin/.debug"
FILES_${PN}-dbg += "${prefix}/apps/org.tizen.ico.statusbar/bin/.debug/StatusBar"
FILES_${PN}-dbg += "${prefix}/apps/org.tizen.ico.homescreen/bin/.debug/HomeScreen"
FILES_${PN}-dbg += "${prefix}/apps/org.tizen.ico.system-controller/bin/.debug"

pkg_postinst_${PN}() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
    # Update the app database.
    #pkg_initdb
    #ail_initdb

}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
    rm -f $D${prefix}/share/applications/org.tizen.ico.homescreen.desktop
    rm -f $D${prefix}/share/applications/org.tizen.ico.statusbar.desktop
    rm -f $D${prefix}/share/applications/org.tizen.ico.onscreen.desktop
    rm -f $D${prefix}/share/applications/org.tizen.ico.system-controller.desktop
    #pkg_initdb
    #ail_initdb

}

PROVIDES_remove := "${@bb.utils.contains('SYS_CTLR_PROVIDER', 'ico-uxf-homescreen',"","system-controller",d)}"
RPROVIDES_ico-uxf-homescreen-system-controller_remove :=  "${@bb.utils.contains('SYS_CTLR_PROVIDER', 'ico-uxf-homescreen','',"system-controller",d)}"
