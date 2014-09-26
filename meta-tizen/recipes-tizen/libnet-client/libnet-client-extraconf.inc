INSANE_SKIP_${PN} = "dev-so"

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

    #License
    mkdir -p ${D}${prefix}/share/license
    cp LICENSE.Flora ${D}${prefix}/share/license/libnet-client
}
