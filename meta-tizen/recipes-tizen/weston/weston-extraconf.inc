inherit useradd

RDEPENDS_${PN} += "xkeyboard-config"
RRECOMMENDS_${PN} = "liberation-fonts"

RDEPENDS_${PN}_remove = "weston-startup"

SRC_URI += "file://make-lcms-explicitly-configurable.patch"
SRC_URI += "file://make-libwebp-explicitly-configurable.patch"

USERADD_PACKAGES = "${PN}"
GROUPADD_PARAM_${PN} = "--system -g 192 weston-launch"

EXTRA_OECONF += "   \
                    --enable-wayland-compositor \
                    --disable-vaapi-recorder \
                    --enable-weston-launch \
                    --enable-drm-compositor \
                    --disable-rdp-compositor \
                    --enable-sys-uid \
                    --with-cairo=image \
                    --enable-egl \
                    --enable-simple-egl-clients \
                    --enable-fbdev-compositor \
                    --disable-headless-compositor \
                    --enable-setuid-install \
                    --enable-demo-clients-install \
                    --disable-lcms \
                    --disable-webp \
                    "

do_configure_prepend() {
    sed -i 's/PKG_CHECK_MODULES(WAYLAND_SCANNER, wayland-scanner)//' configure.ac
}

pkg_preinst_${PN}() {
}

FILES_${PN} += "${prefix}/lib/weston/weston-keyboard"
FILES_${PN} += "${prefix}/lib/weston/weston-desktop-shell"
FILES_${PN} += "${prefix}/lib/weston/cms-static.so"
FILES_${PN} += "${prefix}/lib/weston/weston-screenshooter"
FILES_${PN} += "${prefix}/lib/weston/weston-simple-im"

FILES_${PN} += "${prefix}/bin/weston-scaler"
FILES_${PN} += "${prefix}/bin/weston-stacking"
FILES_${PN} += "${prefix}/bin/weston-multi-resource"
