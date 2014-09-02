inherit pkgconfig cmake

EXTRA_OECMAKE += " \
                    -DCMAKE_VERBOSE_MAKEFILE=ON \
                    -DCMAKE_INSTALL_PREFIX:PATH=${prefix} \
                    -DCMAKE_INSTALL_LIBDIR:PATH=${prefix}/lib \
                    -DINCLUDE_INSTALL_DIR:PATH=${prefix}/include \
                    -DLIB_INSTALL_DIR:PATH=${prefix}/lib \
                    -DSYSCONF_INSTALL_DIR:PATH=${sysconfdir} \
                    -DSHARE_INSTALL_PREFIX:PATH=${prefix}/share \
                    -DCMAKE_SKIP_RPATH:BOOL=ON \
                    -DBUILD_SHARED_LIBS:BOOL=ON \
                    "

do_prep() {

    cd ${S}
    chmod -Rf a+rX,u+w,g-w,o-w ${S}
    cp ${S}/packaging/genivi-shell.manifest .

    ${STAGING_BINDIR_NATIVE}/wayland-scanner code < protocol/ivi-controller.xml > protocol/ivi-controller-protocol.c
}

cmake_do_install_append() {

    rm -f ${D}${infodir}/dir

    find ${D} -regex ".*\.la$" | xargs rm -f --
    find ${D} -regex ".*\.a$" | xargs rm -f --

    install -d ${D}/${prefix}/share/genivi-shell/protocol/
    pwd
    install -m 644 ${S}/protocol/ivi-application.xml ${D}/${prefix}/share/genivi-shell/protocol/
    install -m 644 ${S}/protocol/ivi-controller.xml ${D}/${prefix}/share/genivi-shell/protocol/
    install -m 644 protocol/ivi-application-server-protocol.h ${D}/${prefix}/share/genivi-shell/protocol/
    install -m 644 protocol/ivi-application-protocol.c ${D}/${prefix}/share/genivi-shell/protocol/
    install -m 644 protocol/ivi-controller-server-protocol.h ${D}/${prefix}/share/genivi-shell/protocol/
    install -m 644 protocol/ivi-controller-protocol.c ${D}/${prefix}/share/genivi-shell/protocol/
}

PACKAGES += " genivi-shell-dbg "

FILES_genivi-shell-dbg = "${prefix}/lib/weston/.debug/ivi-controller.so"