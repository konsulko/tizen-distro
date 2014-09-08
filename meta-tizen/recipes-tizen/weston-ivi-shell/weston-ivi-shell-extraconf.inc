inherit useradd

GROUPADD_PARAM_${PN} = "-g 100 users; -g 5000 app; -g 192 weston-launch"

USERADD_PARAM_${PN} += " -u 5000 -d /home/app   -m -g users -G users,weston-launch -r -s /bin/sh app ; "
USERADD_PARAM_${PN} += " -u 9999 -d /home/guest -m -g users -G users,weston-launch -r -s /bin/sh guest "

USERADD_PACKAGES = "${PN}"

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
    for user in app guest; do
        for appdir in desktop manifest dbspace; do
            mkdir -p $D/home/$user/.applications/$appdir
        done
        find $D/home/$user/ -type d -exec chsmack -a User {} \;
        chown -R $user:users $D/home/$user/
    done
}
