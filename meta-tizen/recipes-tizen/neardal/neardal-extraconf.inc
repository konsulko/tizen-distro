do_compile_prepend() {
    sed -i 's@CFLAGS="$CFLAGS -I/usr/include/dlog"@CFLAGS="$CFLAGS -I${STAGING_INCDIR}/dlog"@' configure.ac
}