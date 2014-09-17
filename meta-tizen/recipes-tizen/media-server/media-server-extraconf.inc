SRC_URI += "file://Makefile.am.diff"

do_install_append() {
    rm -fr ${D}/etc
}
