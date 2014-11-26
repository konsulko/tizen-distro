inherit useradd

USERADD_PACKAGES = "${PN}"
GROUPADD_PARAM_${PN} += "--system gsignond"

do_compile() {
    cd ${S}
    LANG=C
    export LANG
    unset DISPLAY
    LD_AS_NEEDED=1; export LD_AS_NEEDED ;

    autotools_do_configure
    oe_runmake -j1
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
    chmod u+s $D${prefix}/bin/gsignond
}

FILES_${PN}-dbg += "/usr/lib/gsignond/extensions/.debug/libextension-test.so"
FILES_${PN}-dbg += "/usr/lib/gsignond/extensions/.debug/libextension-tizen.so"
FILES_${PN}-dbg += "/usr/lib/gsignond/pluginloaders/.debug/gsignond-plugind"
FILES_${PN}-dbg += "/usr/lib/gsignond/gplugins/.debug/libpassword.so"
FILES_${PN}-dbg += "/usr/lib/gsignond/gplugins/.debug/libdigest.so"
FILES_${PN}-dbg += "/usr/lib/gsignond/gplugins/.debug/libssotest.so"
