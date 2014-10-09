do_configure_prepend() {
    sed -i 's@-I/usr/include@-I${STAGING_INCDIR}@g' ico-app-soundsample/src/Makefile.am
    sed -i 's@-I/usr/include@-I${STAGING_INCDIR}@g' ico-app-vicsample/src/Makefile.am
}

FILES_${PN}-dbg += "${prefix}/apps/org.tizen.ico.app-soundsample/bin/.debug"
FILES_${PN}-dbg += "${prefix}/apps/org.tizen.ico.app-vicsample/bin/.debug"
