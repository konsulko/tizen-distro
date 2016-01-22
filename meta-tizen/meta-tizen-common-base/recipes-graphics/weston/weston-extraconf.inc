RDEPENDS_${PN} += "xkeyboard-config"
RRECOMMENDS_${PN} = "liberation-fonts"

RDEPENDS_${PN}_remove = "weston-startup"

SRC_URI += "file://make-lcms-explicitly-configurable.patch"
SRC_URI += "file://make-libwebp-explicitly-configurable.patch"
# SRC_URI += "file://0001-Add-Vivante-EGL-and-GAL2D-compositor-support.patch"
SRC_URI += " \
    file://0001-ENGR00314805-1-Add-Vivante-EGL-support.patch \
    file://0002-ENGR00314805-2-Add-Vivante-GAL2D-support.patch \
    file://0003-ENGR00319247-Distorted-line-and-shadow-if-use-2d-com.patch \
    file://0004-ENGR00320243-Enable-GAL2D-compositor-in-SoloLite.patch \
    file://0005-ENGR00321030-Change-GAL2D-compositor-to-be-default-i.patch \
    file://0006-MGS-389-Fix-for-wrong-FPS-throttling-when-multibuffe.patch \
    file://0007-MGS-391-Weston-Performance-Optimisation-for-single-b.patch \
"
SRC_URI += "file://0001-text-Don-t-crash-if-a-seat-has-no-keyboard.patch"

PACKAGECONFIG_append_mx6q = " cairo-glesv2"
PACKAGECONFIG_append_mx6dl = " cairo-glesv2"
PACKAGECONFIG_append_mx6sx = " cairo-glesv2"
PACKAGECONFIG_remove_mx6sl = "egl"

EXTRA_OECONF += " \
    --disable-libunwind \
    --disable-xwayland-test \
    WESTON_NATIVE_BACKEND=fbdev-backend.so \
"

EXTRA_OECONF += "\
    COMPOSITOR_LIBS="-lGLESv2 -lEGL -lGAL -lwayland-server -lxkbcommon -lpixman-1" \
    FB_COMPOSITOR_LIBS="-lGLESv2 -lEGL -lwayland-server -lxkbcommon" \
"

EXTRA_OECONF += " \
    COMPOSITOR_CFLAGS="-I ${STAGING_INCDIR}/pixman-1 -DLINUX=1 -DEGL_API_FB -DEGL_API_WL" \
    FB_COMPOSITOR_CFLAGS="-DLINUX=1 -DEGL_API_FB -DEGL_API_WL" \
    SIMPLE_EGL_CLIENT_CFLAGS="-DLINUX -DEGL_API_FB -DEGL_API_WL" \
    EGL_TESTS_CFLAGS="-DLINUX -DEGL_API_FB -DEGL_API_WL" \
    CLIENT_CFLAGS="-I ${STAGING_INCDIR}/cairo -I ${STAGING_INCDIR}/pixman-1 -DLINUX -DEGL_API_FB -DEGL_API_WL" \
"

EXTRA_OECONF += "   \
                    --enable-wayland-compositor \
                    --disable-vaapi-recorder \
                    --enable-weston-launch \
                    --enable-drm-compositor \
                    --enable-sys-uid \
                    --enable-egl \
                    --enable-simple-egl-clients \
                    --enable-fbdev-compositor \
                    --disable-headless-compositor \
                    --enable-setuid-install \
                    --enable-demo-clients-install \
                    --disable-lcms \
                    --disable-webp \
                    "

EXTRA_OECONF += "   --disable-rdp-compositor "
                    
EXTRA_OECONF += "   --disable-dbus"

do_configure_prepend() {
    sed -i 's/PKG_CHECK_MODULES(WAYLAND_SCANNER, wayland-scanner)//' configure.ac
}

pkg_preinst_${PN}() {
}

export libexecdir="${prefix}/libexec"

FILES_${PN} += "${prefix}/lib/weston/cms-static.so"

FILES_${PN} += "${prefix}/lib/weston/gal2d-renderer.so"
FILES_${PN} += "${prefix}/bin/weston-scaler"
FILES_${PN} += "${prefix}/bin/weston-stacking"
FILES_${PN} += "${prefix}/bin/weston-multi-resource"

PACKAGE_ARCH_mx6 = "${MACHINE_ARCH}"
