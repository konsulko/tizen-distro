inherit pkgconfig cmake


#PROVIDES by aul
PROVIDES += "aul"

RDEPENDS = ""
#RDEPENDS of aul (aul)
RDEPENDS_aul += "eglibc"
RDEPENDS_aul += "systemd"

#RDEPENDS of aul-dev (aul-dev)
RDEPENDS_aul-dev += "aul"

DEPENDS = ""
#DEPENDS of aul
DEPENDS += "pkgmgr-info"
DEPENDS += "librua"
DEPENDS_append_class-native = " cmake-native"
DEPENDS_append_class-target = " cmake-native"
DEPENDS += "attr"
DEPENDS += "dbus"
DEPENDS += "tizen-platform-config"
DEPENDS += "dlog"
DEPENDS += "xdgmime"
DEPENDS += "ail"
DEPENDS += "bundle"
DEPENDS += "sqlite3"
DEPENDS += "libprivilege-control"
DEPENDS += "app-checker"
DEPENDS += "vconf"
DEPENDS += "privacy-manager"

EXTRA_OECMAKE += " \
                    -DCMAKE_VERBOSE_MAKEFILE=ON \
                    -DCMAKE_INSTALL_LIBDIR:PATH=${prefix}/lib \
                    -DINCLUDE_INSTALL_DIR:PATH=${prefix}/include \
                    -DLIB_INSTALL_DIR:PATH=${prefix}/lib \
                    -DSYSCONF_INSTALL_DIR:PATH=${sysconfdir} \
                    -DSHARE_INSTALL_PREFIX:PATH=${prefix}/share \
                    -DCMAKE_SKIP_RPATH:BOOL=ON \
                    -DBUILD_SHARED_LIBS:BOOL=ON \
                    -DWITH_WAYLAND=On \
                    "

do_prep_append() {
    sed -i 's!/usr/bin/mkdir -p!/bin/mkdir -p!g' ${S}/packaging/ac.service
    # preload_list.txt and preexec_list.txt are generated from .in files so they are located in the build directory instead of the source one
    sed -i 's@INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/legacy/preload_list.txt DESTINATION /usr/share/aul )@INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/legacy/preload_list.txt DESTINATION /usr/share/aul )@' ${S}/CMakeLists.txt
    sed -i 's@INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/feature/preexec_list.txt DESTINATION /usr/share/aul )@INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/feature/preexec_list.txt DESTINATION /usr/share/aul )@' ${S}/CMakeLists.txt
}

do_cmake_install_append() {

    rm -f ${D}${infodir}/dir 
    find ${D} -regex ".*\.la$" | xargs rm -f -- 
    find ${D} -regex ".*\.a$" | xargs rm -f --
 
    mkdir -p ${D}/etc/init.d
    install -m 755 launchpad_run ${D}/etc/init.d
 
    mkdir -p ${D}/etc/rc.d/rc3.d
    mkdir -p ${D}/etc/rc.d/rc4.d
    ln -sf ../../init.d/launchpad_run ${D}/${sysconfdir}/rc.d/rc3.d/S34launchpad_run
    ln -sf ../../init.d/launchpad_run ${D}/${sysconfdir}/rc.d/rc4.d/S80launchpad_run
 
    mkdir -p ${D}${prefix}/dbspace
    sqlite3 ${D}${prefix}/dbspace/.mida.db < ${D}/usr/share/aul/mida_db.sql
    rm -rf ${D}/usr/share/aul/mida_db.sql
 
    mkdir -p ${D}/usr/lib/systemd/system/graphical.target.wants
    mkdir -p ${D}/usr/lib/systemd/user/default.target.wants
    install -m 0644 ${S}/packaging/launchpad-preload@.service ${D}/usr/lib/systemd/system/launchpad-preload@.service
    install -m 0644 ${S}/packaging/ac.service ${D}/usr/lib/systemd/system/ac.service
    ln -s ../launchpad-preload@.service ${D}/usr/lib/systemd/system/graphical.target.wants/launchpad-preload@5000.service
    ln -s ../ac.service ${D}/usr/lib/systemd/system/graphical.target.wants/ac.service
 
    install -m 0644 ${S}/packaging/amd_session_agent.service ${D}/usr/lib/systemd/user/amd_session_agent.service
    ln -s ../amd_session_agent.service ${D}/usr/lib/systemd/user/default.target.wants/amd_session_agent.service
}

aul_files += "${prefix}/share/aul/mida_db.sql"
