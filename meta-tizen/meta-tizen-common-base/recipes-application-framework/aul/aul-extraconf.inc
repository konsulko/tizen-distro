do_prep_append() {
    sed -i 's!/usr/bin/mkdir -p!/bin/mkdir -p!g' ${S}/packaging/ac.service
    # preload_list.txt and preexec_list.txt are generated from .in files so they are located in the build directory instead of the source one
    sed -i 's@INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/legacy/preload_list.txt DESTINATION /usr/share/aul )@INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/legacy/preload_list.txt DESTINATION /usr/share/aul )@' ${S}/CMakeLists.txt
    sed -i 's@INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/feature/preexec_list.txt DESTINATION /usr/share/aul )@INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/feature/preexec_list.txt DESTINATION /usr/share/aul )@' ${S}/CMakeLists.txt
}

SRC_URI_append_class-native = " file://remove-dlog-for-native-build.patch"
aul_files += "${prefix}/share/aul/mida_db.sql"


RDEPENDS_${PN}_remove_class-native = "systemd-native"
RDEPENDS_${PN}_remove_class-native = "glibc-native"

DEPENDS_remove_class-native = "dlog-native"

EXTRA_OECMAKE+="-DCMAKE_AR:PATH=ar"

do_install_append() {

 mkdir -p ${D}${prefix}/lib/systemd/user/default.target.wants
 ln -s ../amd_session_agent.service ${D}${prefix}/lib/systemd/user/default.target.wants/amd_session_agent.service
 
 mkdir -p ${D}${systemd_unitdir}/system/default.target.wants
 ln -s ../ac.service ${D}${systemd_unitdir}/system/default.target.wants/ac.service
 
}

FILES_${PN} += "${prefix}/lib/systemd/user/default.target.wants/amd_session_agent.service"
FILES_${PN} += "${systemd_unitdir}/system/default.target.wants/ac.service"