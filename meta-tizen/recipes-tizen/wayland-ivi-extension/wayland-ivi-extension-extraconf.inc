DEPENDS += "wayland-native"
DEPENDS += "weston-ivi-shell"

RPROVIDES_genivi-shell += "wayland-ivi-extension"


do_prep() {

    cd ${S}
    chmod -Rf a+rX,u+w,g-w,o-w ${S}
    cp ${S}/packaging/genivi-shell.manifest .

    sed -i "s@\${LIBS} \${WESTON_LIBDIR}/weston/ivi-shell.so@\${LIBS} ${PKG_CONFIG_SYSROOT_DIR}\${WESTON_LIBDIR}/weston/ivi-shell.so@g" ${S}/weston-ivi-shell/CMakeLists.txt 
}

cmake_do_configure_prepend() {
    ${STAGING_BINDIR_NATIVE}/wayland-scanner code < protocol/ivi-controller.xml > protocol/ivi-controller-protocol.c
}

PACKAGES += " genivi-shell-dbg "

FILES_genivi-shell-dbg = "${prefix}/lib/weston/.debug/ivi-controller.so"

B="${S}"

FILES_genivi-shell += "${prefix}/bin/IVISurfaceCreator"