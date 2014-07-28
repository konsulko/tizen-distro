INSANE_SKIP_${PN} = "dev-so"

EXTRA_OECONF += " \
    --with-edje-cc=${STAGING_BINDIR_NATIVE}/edje_cc \
    --with-eolian-gen=${STAGING_BINDIR_NATIVE}/eolian_gen \
    --with-eolian-cxx=${STAGING_BINDIR_NATIVE}/eolian_cxx \
    --with-binary-edje-cc=${STAGING_BINDIR_NATIVE}/edje_cc \
    --disable-physics \
    --enable-always-build-examples=no \
"

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


DEPENDS_class-target = " zlib tiff ibus harfbuzz openssl curl fontconfig gstreamer1.0-plugins-base systemd freetype wayland dlog glib-2.0 lua libtbm libbullet libpng sensor pixman libsndfile1 libcheck giflib udev gnutls mesa util-linux vconf libxkbcommon fribidi libjpeg-turbo dbus gstreamer1.0 pulseaudio libexif"
DEPENDS_class-native = " zlib-native tiff-native openssl-native curl-native fontconfig-native freetype-native wayland-native glib-2.0-native lua-native libpng-native pixman-native  libcheck-native giflib-native gnutls-native  util-linux-native vconf-native  fribidi-native dbus-native "

DEPENDS_append_class-target = " efl-native "

# new efl doesn't have option to disable eeze build and we don't want to provide udev-native just to build eeze-native we don't need
do_configure_prepend_class-native() {
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
 
 
   make \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
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

 rm -rf ${D}${prefix}/lib/ecore/system/upower
  
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