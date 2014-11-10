INSANE_SKIP_${PN} = "dev-so"

DEPENDS += "efl-native"

# Build efl native with the fewest dependency possible
DEPENDS_class-native = ""
DEPENDS_class-native += "zlib-native"
DEPENDS_class-native += "tiff-native"
DEPENDS_class-native += "openssl-native"
DEPENDS_class-native += "curl-native"
DEPENDS_class-native += "fontconfig-native"
DEPENDS_class-native += "freetype-native"
DEPENDS_class-native += "wayland-native"
DEPENDS_class-native += "glib-2.0-native"
DEPENDS_class-native += "lua-native"
DEPENDS_class-native += "libpng-native"
DEPENDS_class-native += "pixman-native"
DEPENDS_class-native += "libcheck-native"
DEPENDS_class-native += "giflib-native"
DEPENDS_class-native += "gnutls-native"
DEPENDS_class-native += "util-linux-native"
DEPENDS_class-native += "vconf-native"
DEPENDS_class-native += "fribidi-native"
DEPENDS_class-native += "dbus-native"

EXTRA_OECONF += " \
    --with-edje-cc=${STAGING_BINDIR_NATIVE}/edje_cc \
    --with-eolian-gen=${STAGING_BINDIR_NATIVE}/eolian_gen \
    --with-eolian-cxx=${STAGING_BINDIR_NATIVE}/eolian_cxx \
    --with-binary-edje-cc=${STAGING_BINDIR_NATIVE}/edje_cc \
    --disable-physics \
    --enable-always-build-examples=no \
"

# Disable as much options as possible for efl-native
EXTRA_OECONF_class-native = " \
    --disable-fontconfig \
    --disable-audio \
    --with-x11=none \
    --disable-image-loader-bmp \
    --disable-image-loader-eet \
    --disable-image-loader-generic \
    --disable-image-loader-gif \
    --disable-image-loader-ico \
    --disable-image-loader-jp2k \
    --disable-image-loader-pmaps \
    --disable-image-loader-psd \
    --disable-image-loader-tga \
    --disable-image-loader-wbmp \
    --disable-image-loader-webp \
    --disable-image-loader-xpm \
    --disable-systemd \
    --disable-gstreamer \
    --disable-gstreamer1 \
    --disable-physics \
    --enable-i-really-know-what-i-am-doing-and-that-this-will-probably-break-things-and-i-will-fix-them-myself-and-send-patches-aaa \
    --enable-lua-old \
"

do_configure_prepend() {
    # Fix configure error: "error: required file './ABOUT-NLS' not found"
    sed -i 's/AM_INIT_AUTOMAKE(\[1.6 dist-bzip2 -Wall color-tests\])/AM_INIT_AUTOMAKE(\[1.6 dist-bzip2 -Wall color-tests foreign\])/' configure.ac
}

do_configure_prepend_class-native() {
    # efl doesn't have option to disable eeze build and we don't want to provide udev-native just to build eeze-native since don't need it
    sed -i 's/EFL_LIB_START_OPTIONAL(\[Eeze\], \[test "${have_linux}" = "yes"\])/EFL_LIB_START_OPTIONAL([Eeze], [test "${no-we-really-dont-want-native-eeze}" = "yes"])/g' ${S}/configure.ac
}

do_install_prepend () {
    for i in `find ${B}/ -name "*.pc" -type f` ; do \
        sed -i -e 's:-L${STAGING_LIBDIR}:-L\$\{libdir\}:g' -e 's:-I${STAGING_LIBDIR}:-I\$\{libdir\}:g' -e 's:-I${STAGING_INCDIR}:-I\$\{includedir\}:g' $i
    done
}

do_install_class-native() {
    echo export RPM_BUILD_ROOT=${D}
    cd ${S}
    LANG=C
    export LANG
    unset DISPLAY
    rm -rf ${D}
    mkdir -p ${D}

    # "oe_runmake" fails so we use "make" instead
    make \
        DESTDIR=${D} \
        INSTALL_ROOT=${D} \
        BINDIR=${prefix}/bin \
    install

    rm -f ${D}${infodir}/dir 
    find ${D} -regex ".*\.la$" | xargs rm -f -- 
    find ${D} -regex ".*\.a$" | xargs rm -f --

    # We don't build the examples so don't install them
    # oe_runmake datadir=${D}${prefix}/share install-examples
    rm -rf ${D}${prefix}/lib/ecore/system/upower
}

do_install() {
    echo export RPM_BUILD_ROOT=${D}
    cd ${S}
    LANG=C
    export LANG
    unset DISPLAY
    rm -rf ${D}
    mkdir -p ${D}

    oe_runmake \
        DESTDIR=${D} \
        INSTALL_ROOT=${D} \
        BINDIR=${prefix}/bin \
    install

    rm -f ${D}${infodir}/dir 
    find ${D} -regex ".*\.la$" | xargs rm -f -- 
    find ${D} -regex ".*\.a$" | xargs rm -f --

    # We don't build the examples so don't install them
    # oe_runmake datadir=${D}${prefix}/share install-examples
    rm -rf ${D}${prefix}/lib/ecore/system/upower
}

pkg_postinst_ecore() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
    f="$D/etc/profile.d/ecore.sh"
    grep --silent EFL_WAYLAND_USE_XDG_SHELL "$f" \
        || printf "\nEFL_WAYLAND_USE_XDG_SHELL='defined'\nexport EFL_WAYLAND_USE_XDG_SHELL\n" >> "$f"
    grep --silent ECORE_EVAS_ENGINE "$f" \
        || printf "\nECORE_EVAS_ENGINE=wayland_shm\n[ ! -d /dev/dri ] || ECORE_EVAS_ENGINE=wayland_egl\nexport ECORE_EVAS_ENGINE" >> "$f"
    grep --silent ECORE_IMF_MODULE "$f" \
        || printf "\nECORE_IMF_MODULE=wayland\nexport ECORE_IMF_MODULE\n" >> "$f"

}

FILES_${PN}-dbg += "${prefix}/lib/eeze/modules/sensor/tizen/v-1.9/.debug"
FILES_${PN}-dbg += "${prefix}/lib/eeze/modules/sensor/udev/v-1.9/.debug"
FILES_${PN}-dbg += "${prefix}/lib/ecore_evas/engines/extn/v-1.9/.debug"
FILES_${PN}-dbg += "${prefix}/lib/ecore_evas/engines/wayland/v-1.9/.debug"
FILES_${PN}-dbg += "${prefix}/lib/ethumb/modules/emotion/v-1.9/.debug"
FILES_${PN}-dbg += "${prefix}/lib/ethumb_client/utils/v-1.9/.debug"
FILES_${PN}-dbg += "${prefix}/lib/edje/modules/emotion/v-1.9/.debug"
FILES_${PN}-dbg += "${prefix}/lib/edje/utils/v-1.9/.debug"
FILES_${PN}-dbg += "${prefix}/lib/emotion/modules/gstreamer1/v-1.9/.debug"
FILES_${PN}-dbg += "${prefix}/lib/efreet/v-1.9/.debug"
FILES_${PN}-dbg += "${prefix}/lib/evas/modules/savers/tiff/v-1.9/.debug"
FILES_${PN}-dbg += "${prefix}/lib/evas/modules/loaders/tiff/v-1.9/.debug"
FILES_${PN}-dbg += "${prefix}/lib/evas/modules/loaders/gif/v-1.9/.debug"
FILES_${PN}-dbg += "${prefix}/lib/evas/modules/engines/wayland_shm/v-1.9/.debug"
FILES_${PN}-dbg += "${prefix}/lib/evas/modules/engines/wayland_egl/v-1.9/.debug"
FILES_${PN}-dbg += "${prefix}/lib/ecore_imf/modules/wayland/v-1.9/.debug"
FILES_${PN}-dbg += "${prefix}/lib/ecore/system/systemd/v-1.9/.debug"
FILES_${PN}-dbg += "${prefix}/lib/ecore/system/tizen/v-1.9/.debug"
FILES_${PN}-dbg += "${prefix}/lib/evas/cserve2/bin/v-1.9/.debug"
