DEPENDS += "config-tizen-ivi"
RDEPENDS_${PN} += "config-tizen-ivi"

do_configure_prepend() {
    # pkg-config check for wayland scanner even though it is present and wayland-scanner.pc seems ok.
    sed -i 's/PKG_CHECK_MODULES(WAYLAND_SCANNER, wayland-scanner)//' configure.ac
}

PACKAGES += " weston-ivi-shell-clients-dbg "

FILES_weston-ivi-shell-clients-dbg += "/usr/bin/ivi/.debug/weston-cliptest"
FILES_weston-ivi-shell-clients-dbg += "/usr/bin/ivi/.debug/weston-smoke"
FILES_weston-ivi-shell-clients-dbg += "/usr/bin/ivi/.debug/weston-editor"
FILES_weston-ivi-shell-clients-dbg += "/usr/bin/ivi/.debug/weston-transformed"
FILES_weston-ivi-shell-clients-dbg += "/usr/bin/ivi/.debug/weston-clickdot"
FILES_weston-ivi-shell-clients-dbg += "/usr/bin/ivi/.debug/weston-calibrator"
FILES_weston-ivi-shell-clients-dbg += "/usr/bin/ivi/.debug/weston-resizor"
FILES_weston-ivi-shell-clients-dbg += "/usr/bin/ivi/.debug/weston-simple-egl"
FILES_weston-ivi-shell-clients-dbg += "/usr/bin/ivi/.debug/weston-simple-touch"
FILES_weston-ivi-shell-clients-dbg += "/usr/bin/ivi/.debug/weston-image"
FILES_weston-ivi-shell-clients-dbg += "/usr/bin/ivi/.debug/weston-flower"
FILES_weston-ivi-shell-clients-dbg += "/usr/bin/ivi/.debug/weston-simple-shm"
FILES_weston-ivi-shell-clients-dbg += "/usr/bin/ivi/.debug/weston-subsurfaces"
FILES_weston-ivi-shell-clients-dbg += "/usr/bin/ivi/.debug/weston-fullscreen"
FILES_weston-ivi-shell-clients-dbg += "/usr/bin/ivi/.debug/weston-eventdemo"
FILES_weston-ivi-shell-clients-dbg += "/usr/bin/ivi/.debug/weston-dnd"

FILES_${PN}-dbg += "/usr/lib/weston/.debug/hmi-controller.so"
FILES_${PN}-dbg += "/usr/lib/weston/.debug/gl-renderer.so"
FILES_${PN}-dbg += "/usr/lib/weston/.debug/ivi-shell.so"
FILES_${PN}-dbg += "/usr/lib/weston/.debug/ivi-layout.so"

FILES_${PN} += "/usr/lib/weston-ivi-shell/weston-ivi-shell-user-interface"
FILES_${PN} += "/usr/lib/weston/gl-renderer.so"

FILES_${PN}-dev += "/usr/lib/pkgconfig/weston.pc"

do_install_append() {
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
chown -R app:app /home/app

# Since weston-launch runs with the "User" label, the app
# home dir must have the same label
chsmack -a User /home/app

# Enable a logind session for 'app' user on seat0 (the default seat for
# graphical sessions)
mkdir -p /usr/lib/systemd/system/graphical.target.wants
ln -s ../user-session-launch@.service /usr/lib/systemd/system/graphical.target.wants/user-session-launch@seat0-5000.service
ln -sf weston.target  /usr/lib/systemd/user/default.target

# Add over-riding environment to enable the web runtime to
# run on an IVI image as a different user then the tizen user
# Some notes on some of the variables:
#  - ELM_THEME is needed in order for the wrt to have visible content
#  - WRT_PROCESS_POOL_DISABLE is a work around for TIVI-2062
cat > /etc/sysconfig/wrt <<EOF
DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/5000/dbus/user_bus_socket
XDG_RUNTIME_DIR=/run/user/5000
ELM_ENGINE=wayland_egl
ECORE_EVAS_ENGINE=wayland_egl
ELM_THEME=tizen-HD-light
WRT_PROCESS_POOL_DISABLE=1
EOF

# Use the same over-rides for the native prelaunch daemon
cp /etc/sysconfig/wrt /etc/sysconfig/launchpad

# Add a rule to ensure the app user has permissions to
# open the graphics device
cat > /etc/udev/rules.d/99-dri.rules <<EOF
SUBSYSTEM=="drm", MODE="0666"
EOF
#------------------------------------------
  
}
