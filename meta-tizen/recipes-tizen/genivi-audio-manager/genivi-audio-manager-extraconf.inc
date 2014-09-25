LDFLAGS += "-lpthread"

do_configure_prepend() {
   sed -i 's@PATHS /lib@PATHS ${STAGING_DIR_HOST}/usr/lib@g' ${S}/cmake/FindMURPHY.cmake
   sed -i 's@^/usr/include@${STAGING_DIR_HOST}/usr/include@g' ${S}/cmake/FindMURPHY.cmake
   
   sed -i 's@PATHS "/usr/include/dbus-1.0"@PATHS "${STAGING_DIR_HOST}/usr/include/dbus-1.0"@g' ${S}/cmake/FindDBUS.cmake
   sed -i 's@^/usr/lib@${STAGING_DIR_HOST}/usr/lib@g' ${S}/cmake/FindDBUS.cmake
   sed -i 's@PATHS "/usr/lib"@NO_DEFAULT_PATH PATHS "${STAGING_DIR_HOST}/usr/lib"@g' ${S}/cmake/FindDBUS.cmake
}

INSANE_SKIP_${PN} = "dev-so"

FILES_${PN}-dbg += "${prefix}/lib/audioManager/command/.debug"
FILES_${PN}-dbg += "${prefix}/lib/audioManager/control/.debug"
FILES_${PN}-dbg += "${prefix}/lib/audioManager/routing/.debug"