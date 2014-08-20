do_compile_prepend() {
    export BUILD_SYS=${BUILD_SYS}
    export HOST_SYS=${HOST_SYS}
    export STAGING_LIBDIR=${STAGING_LIBDIR}
    export STAGING_INCDIR=${STAGING_INCDIR}
}

FILES_${PN}-dbg += "${prefix}/lib/python2.7/site-packages/.debug"

FILES_${PN} += "/usr/share"
