do_configure_prepend() {
    sed -i 's@-I/usr/include@-I${STAGING_INCDIR}@g' ico-app-soundsample/src/Makefile.am
    sed -i 's@-I/usr/include@-I${STAGING_INCDIR}@g' ico-app-vicsample/src/Makefile.am
}

FILES_${PN}-dbg += "${prefix}/apps/org.tizen.ico.app-soundsample/bin/.debug"
FILES_${PN}-dbg += "${prefix}/apps/org.tizen.ico.app-vicsample/bin/.debug"

pkg_postinst_${PN}() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
    # This icons exists in main weston package so we don't package it in.
    # Create a symbolic link to it instead.
    ln -sf $D${prefix}/share/weston/terminal.png $D${prefix}/share/icons/default/small/
    # Update the app database.
    #pkg_initdb
    #ail_initdb

}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    if [ "$1" = "0" ]; then
    [ "x$D" == "x" ] && ldconfig
    rm -f $D${prefix}/share/applications/org.tizen.ico.app-soundsample.desktop
    rm -f $D${prefix}/share/applications/org.tizen.ico.app-vicsample.desktop
    rm -f $D${prefix}/share/applications/browser.desktop
    rm -f $D${prefix}/share/applications/terminal.desktop
    rm -f $D${prefix}/share/icons/default/small/terminal.png
    # Update the app database.
    #pkg_initdb
    #ail_initdb
    fi

}