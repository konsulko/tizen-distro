do_install_prepend() {
    RPM_BUILD_ROOT=${D}
}

do_install_append() {
    ln -snf ../../lib/libkeyutils.so.1 ${D}/usr/lib/libkeyutils.so
}