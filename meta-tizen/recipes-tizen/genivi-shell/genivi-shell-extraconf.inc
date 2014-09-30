RPROVIDES_genivi-shell += "wayland-ivi-extension"

DEPENDS += "wayland-native"
DEPENDS += "weston-ivi-shell"

INSANE_SKIP_genivi-shell-dev = "staticdev"

B="${S}"

do_prep() {
    cd ${S}
    chmod -Rf a+rX,u+w,g-w,o-w ${S}
    cp ${S}/packaging/genivi-shell.manifest .

    ${STAGING_BINDIR_NATIVE}/wayland-scanner code < protocol/ivi-controller.xml > protocol/ivi-controller-protocol.c
    sed -i "s@\${LIBS} \${WESTON_LIBDIR}/weston/ivi-shell.so@\${LIBS} ${PKG_CONFIG_SYSROOT_DIR}\${WESTON_LIBDIR}/weston/ivi-shell.so@g" ${S}/weston-ivi-shell/CMakeLists.txt 
}

PACKAGES += " genivi-shell-dbg "

FILES_genivi-shell-dbg = "${prefix}/lib/weston/.debug/ivi-controller.so"

FILES_genivi-shell += "${prefix}/bin/IVISurfaceCreator"
