FILESEXTRAPATHS_prepend := "${THISDIR}/efl"



DEPENDS_class-native = "sensor mesa freetype-native  libpng-native jpeg-native tiff-native libfribidi-native glib-2.0-native dbus-native "
DEPENDS = " sensor mesa virtual/libiconv tslib curl glib-2.0 gnutls pkgconfig zlib jpeg openssl libsndfile1 dbus libexif librsvg libcheck freetype libpng tiff   fontconfig libfribidi giflib udev efl-native"

inherit efl gettext pkgconfig

BBCLASSEXTEND = "native"

PROVIDES += "ecore edje eet eeze efreet eina eio embryo emotion ethumb evas eldbus"

# we don't have bullet for physics
# You have chosen to disable physics support. This disables lots of
# core functionality and is effectively never tested. You are going
# to find features that suddenly don't work and as a result cause
# a series of breakages. This is simply not tested so you are on
# your own in terms of ensuring everything works if you do this

FILESEXTRAPATHS_prepend := "${THISDIR}/efl:"

#SRC_URI = "file://0001-Add-spec-file-and-enable-Tizen-build.patch"
#SRC_URI += "file://0002-Enable-gles-building-with-efl-and-disable-SHAD_TEXSA.patch"
#SRC_URI += "file://0003-Fix-ivi-building-issue.patch"
#SRC_URI += "file://0004-Enable-installing-examples-binaries.patch"
#SRC_URI += "file://0005-Enable-building-multiple-binary-packages.patch"

EXTRA_OECONF = " \
    --disable-physics \
    --enable-i-really-know-what-i-am-doing-and-that-this-will-probably-break-things-and-i-will-fix-them-myself-and-send-patches-aaa \
"
EXTRA_OECONF_append_class-target = " \
      --enable-tizen \
      --enable-g-main-loop \
      --disable-xim \
      --disable-scim \
      --disable-gesture \
      --with-tests=regular \
      --enable-wayland \
      --enable-egl \
      --with-opengl=es \
      --enable-tile-rotate \
      --disable-rpath \
      --with-x11=none \
      --enable-tile-rotate \
      --disable-rpath \
      --enable-systemd \
      --enable-lua-old \
      --enable-i-really-know-what-i-am-doing-and-that-this-will-probably-break-things-and-i-will-fix-them-myself-and-send-patches-aaa \
      --with-tests=none \
      --with-bin-edje-cc=${STAGING_BINDIR_NATIVE}/edje_cc \
"
EXTRA_OECONF_append_class-native = " \
"


RDEPENDS_ecore = "ecore-audio ecore-input-evas ecore-input ecore-imf-evas ecore-imf ecore-file ecore-con ecore-ipc ecore-evas"
