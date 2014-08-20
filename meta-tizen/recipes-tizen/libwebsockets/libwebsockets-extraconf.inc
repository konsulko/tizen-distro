inherit pkgconfig cmake

EXTRA_OECMAKE += " -DCMAKE_VERBOSE_MAKEFILE=ON \
                    -DCMAKE_INSTALL_PREFIX:PATH=${prefix} \
                    -DCMAKE_INSTALL_LIBDIR:PATH=${prefix}/lib \
                    -DINCLUDE_INSTALL_DIR:PATH=${prefix}/include \
                    -DLIB_INSTALL_DIR:PATH=${prefix}/lib \
                    -DSYSCONF_INSTALL_DIR:PATH=${sysconfdir} \
                    -DSHARE_INSTALL_PREFIX:PATH=${prefix}/share \
                    -DCMAKE_SKIP_RPATH:BOOL=ON \
                    -DBUILD_SHARED_LIBS:BOOL=ON \
                    -DWITH_SSL=On \
                    -DWITH_SD_DAEMON=ON "

cmake_do_install_append() {
    rm -f ${D}${infodir}/dir
    find ${D} -regex ".*\.la$" | xargs rm -f --
    find ${D} -regex ".*\.a$" | xargs rm -f --
}
