do_prep() {

    cd ${S}
    chmod -Rf a+rX,u+w,g-w,o-w ${S}
 
    mkdir -p weston
    cp -av ${STAGING_DIR_TARGET}/usr/share/genivi-shell/protocol/*.xml weston/

    ls weston/*.xml | while read protocol ; do
        ${STAGING_BINDIR_NATIVE}/wayland-scanner client-header < "${protocol}" > "${protocol/.xml/}-client-protocol.h"
        ${STAGING_BINDIR_NATIVE}/wayland-scanner code < "${protocol}" > "${protocol/.xml/.c}"
    done
}

do_compile_prepend()  {
 find ${S} -name Makefile.am -exec sed -i "s@-I/usr/include/ico-util@-I${PKG_CONFIG_SYSROOT_DIR}/usr/include/ico-util@g" {} \;
 find ${S} -name Makefile.am -exec sed -i "s@-I/usr/include/ilm@-I${PKG_CONFIG_SYSROOT_DIR}/usr/include/ilm@g" {} \;
 find ${S} -name Makefile.am -exec sed -i "s@-I/usr/include/layermanager@-I${PKG_CONFIG_SYSROOT_DIR}/usr/include/layermanager@g" {} \;
 find ${S} -name Makefile.am -exec sed -i "s@-I/usr/include/ico-uxf-weston-plugin@-I${PKG_CONFIG_SYSROOT_DIR}/usr/include/ico-uxf-weston-plugin@g" {} \;
 
 sed -i "s@-I/usr/include/ico-util@-I${PKG_CONFIG_SYSROOT_DIR}/usr/include/ico-util@g" ${S}/configure.ac
}


FILES_${PN} += "${datadir}/icons/default/small/org.tizen.ico.onscreen.png"
FILES_${PN} += "${datadir}/icons/default/small/org.tizen.ico.homescreen.png"
FILES_${PN} += "${datadir}/icons/default/small/org.tizen.ico.statusbar.png"

INSANE_SKIP_${PN} = "dev-so"
#FILES_${PN}-system-controller-dev += "${prefix}/lib/libico-state-machine.so"

FILES_${PN}-dbg += "${prefix}/apps/org.tizen.ico.onscreen/bin/.debug"
FILES_${PN}-dbg += "${prefix}/apps/org.tizen.ico.statusbar/bin/.debug/StatusBar"
FILES_${PN}-dbg += "${prefix}/apps/org.tizen.ico.homescreen/bin/.debug/HomeScreen"
FILES_${PN}-dbg += "${prefix}/apps/org.tizen.ico.system-controller/bin/.debug"