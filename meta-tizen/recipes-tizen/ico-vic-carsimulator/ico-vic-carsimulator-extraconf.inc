#SRC_URI += "file://0001-fix-build-for-yocto-64b.patch"

DEPENDS += "pkgconfig"

do_configure_prepend() {
    sed -i 's@-I/usr/include/json-glib-1.0@-I${STAGING_INCDIR}/json-glib-1.0@' src/Makefile.am
}
