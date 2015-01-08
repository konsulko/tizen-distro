DEPENDS += "config-tizen-ivi"
RDEPENDS_${PN} += "config-tizen-ivi"

do_configure_prepend() {
    # pkg-config check for wayland scanner even though it is present and wayland-scanner.pc seems ok.
    sed -i 's/PKG_CHECK_MODULES(WAYLAND_SCANNER, wayland-scanner)//' configure.ac
}

do_install_append() {
    # Remove files already provided by weston
    rm -fr ${D}/usr/include/weston/config-parser.h
    rm -fr ${D}/usr/include/weston/compositor.h
    rm -fr ${D}/usr/include/weston/zalloc.h
    rm -fr ${D}/usr/include/weston/version.h
    rm -fr ${D}/usr/include/weston/matrix.h
    rm -fr ${D}/usr/share/weston/sign_close.png
    rm -fr ${D}/usr/share/weston/sign_minimize.png
    rm -fr ${D}/usr/share/weston/sign_maximize.png
    rm -fr ${D}/usr/share/weston/terminal.png
    rm -fr ${D}/usr/share/weston/icon_window.png
    rm -fr ${D}/usr/share/weston/pattern.png
    rm -fr ${D}/usr/share/weston/border.png
    rm -fr ${D}/usr/lib/weston/gl-renderer.so
    rm -fr ${D}/usr/share/weston/wayland.svg
    rm -fr ${D}/usr/lib/pkgconfig/weston.pc
    rm -fr ${D}/usr/bin/weston-terminal
    rm -fr ${D}/usr/bin/weston
    rm -fr ${D}/usr/bin/weston-info
    rm -fr ${D}/usr/lib/pkgconfig
    rm -fr ${D}/usr/lib/weston/desktop-shell.so
    rm -fr ${D}/usr/lib/weston/.debug/desktop-shell.so
    rm -fr ${D}/usr/lib/weston/gl-renderer.so
    rm -fr ${D}/usr/lib/weston/.debug/gl-renderer.so
    rm -fr ${D}/usr/bin/weston-calibrator
    rm -fr ${D}${prefix}/bin/weston-scaler
    rm -fr ${D}${prefix}/bin/weston-stacking
    rm -fr ${D}${prefix}/bin/weston-multi-resource
}

pkg_postinst_${PN} () {
#    for user in app guest; do
    for user in app ; do
        for appdir in desktop manifest dbspace; do
            mkdir -p $D/home/$user/.applications/$appdir
        done
        find $D/home/$user/ -type d -exec chsmack -a User {} \;
        chown -R $user:users $D/home/$user/
    done
    
    #------------------------------------------
    # Temporary work around for bug in filesystem package resulting in the 'app' user home
    # directory being only readable by root
    chown -R app:app $D/home/app

    # Since weston-launch runs with the "User" label, the app
    # home dir must have the same label
    chsmack -a User $D/home/app

    # Add over-riding environment to enable the web runtime to
    # run on an IVI image as a different user then the tizen user
    # Some notes on some of the variables:
    #  - ELM_THEME is needed in order for the wrt to have visible content
    #  - WRT_PROCESS_POOL_DISABLE is a work around for TIVI-2062
    cat > $D/etc/sysconfig/wrt << EOF
    DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/5000/dbus/user_bus_socket
    XDG_RUNTIME_DIR=/run/user/5000
    ELM_ENGINE=wayland_egl
    ECORE_EVAS_ENGINE=wayland_egl
    ELM_THEME=tizen-HD-light
    WRT_PROCESS_POOL_DISABLE=1
EOF

    # Use the same over-rides for the native prelaunch daemon
    cp $D/etc/sysconfig/wrt $D/etc/sysconfig/launchpad

 # Add a rule to ensure the 'display','genivi' user has permissions to
 # open the graphics device
 mkdir -p ${D}${sysconfdir}/udev/rules.d
 cat >${D}${sysconfdir}/udev/rules.d/99-dri.rules <<'EOF'
 SUBSYSTEM=="drm", MODE="0660", GROUP="video", SECLABEL{smack}="*"
EOF
 
 # user 'display' must own /dev/tty7 for weston to start correctly
 cat >${D}${sysconfdir}/udev/rules.d/99-tty.rules <<'EOF'
 SUBSYSTEM=="tty", KERNEL=="tty7", OWNER="genivi", SECLABEL{smack}="^"
EOF
 
 # user 'display' must also be able to access /dev/input/*
 cat >${D}${sysconfdir}/udev/rules.d/99-input.rules <<'EOF'
 SUBSYSTEM=="input", MODE="0660", GROUP="input", SECLABEL{smack}="^"
EOF
    #------------------------------------------
}

PACKAGES += " weston-ivi-shell-clients-dbg "

FILES_weston-ivi-shell-clients-dbg += "${prefix}/bin/ivi/.debug"
FILES_${PN}-dbg += "${prefix}/lib/weston/.debug"


FILES_${PN} += "${prefix}/lib/weston-ivi-shell/weston-ivi-shell-user-interface"
FILES_${PN} += "${prefix}/lib/weston-ivi-shell/weston-keyboard"
FILES_${PN} += "${prefix}/lib/weston-ivi-shell/weston-desktop-shell"
FILES_${PN} += "${prefix}/lib/weston-ivi-shell/weston-screenshooter"
FILES_${PN} += "${prefix}/lib/weston-ivi-shell/weston-simple-im"
FILES_${PN} += "${prefix}/lib/weston/cms-static.so"
FILES_${PN} += "${prefix}/bin/weston-calibrator"
FILES_${PN} += "${sysconfdir}/udev/rules.d/*"

FILES_${PN}-dev += "${prefix}/include/weston/ivi-shell-ext.h"
