inherit pkgconfig cmake

SRC_URI_append_class-native = " file://remove-dlog-for-native-build.patch"

RDEPENDS_${PN}_remove_class-native = "systemd-native"
DEPENDS_remove_class-native = "dlog-native"

DEPENDS_class-target += "ail-native"
DEPENDS_class-target += "libslp-db-util"
DEPENDS_class-target += "xdgmime"
DEPENDS_class-target += "vconf"

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
                    -DTZ_SYS_RW_DESKTOP_APP=${prefix}/share/applications \
                    -DBUILD_PKGTYPE=rpm \
                    -DSMACK=Off \
                    "

cmake_do_install_append() {

    rm -f ${D}${infodir}/dir

    find ${D} -regex ".*\.la$" | xargs rm -f --
    find ${D} -regex ".*\.a$" | xargs rm -f --

    mkdir -p ${D}${prefix}/dbspace/
    mkdir -p ${D}${prefix}/share/applications/
}

ail_files += "/usr/dbspace"