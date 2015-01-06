do_install_append() {
    ln -snf libkeyutils.so.1 ${D}/usr/lib/libkeyutils.so
}
