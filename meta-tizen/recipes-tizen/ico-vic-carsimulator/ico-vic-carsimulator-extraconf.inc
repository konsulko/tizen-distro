do_configure_prepend() {
    sed -i 's@-I/usr/include/glib-2.0 -I/usr/include/json-glib-1.0 -I/usr/lib/glib-2.0/include@-I${STAGING_INCDIR}/glib-2.0 -I${STAGING_INCDIR}/json-glib-1.0 -I${STAGING_LIBDIR}/glib-2.0/include@' src/Makefile.am
}