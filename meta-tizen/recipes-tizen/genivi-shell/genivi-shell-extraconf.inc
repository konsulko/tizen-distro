DEPENDS += "wayland-native"
DEPENDS += "weston-ivi-shell"

INSANE_SKIP_${PN}-dev = "staticdev"

B="${S}"

do_prep() {
    cd ${S}
    chmod -Rf a+rX,u+w,g-w,o-w ${S}
    cp ${S}/packaging/genivi-shell.manifest .
}

do_compile_prepend() {
    cd ${S}

    ${STAGING_BINDIR_NATIVE}/wayland-scanner code < protocol/ivi-controller.xml > protocol/ivi-controller-protocol.c
    sed -i "s@\${LIBS} \${WESTON_LIBDIR}/weston/ivi-shell.so@\${LIBS} ${PKG_CONFIG_SYSROOT_DIR}\${WESTON_LIBDIR}/weston/ivi-shell.so@g" ${S}/weston-ivi-shell/CMakeLists.txt 
}

do_install_append() {
    # Remove source files
    rm -rf ${D}/usr/src
}

FILES_${PN}-dbg = "${prefix}/bin/.debug/IVISurfaceCreator"
FILES_${PN}-dbg = "${prefix}/bin/.debug/LayerManagerControl"
FILES_${PN}-dbg = "${prefix}/bin/.debug/EGLWLMockNavigation"
FILES_${PN}-dbg = "${prefix}/lib/.debug/libilmCommon.so.1.2.0"
FILES_${PN}-dbg = "${prefix}/lib/.debug/libilmControl.so.1.2.0"
FILES_${PN}-dbg = "${prefix}/lib/.debug/libilmClient.so.1.2.0"
FILES_${PN}-dbg = "${prefix}/lib/weston/.debug/ivi-controller.so"

