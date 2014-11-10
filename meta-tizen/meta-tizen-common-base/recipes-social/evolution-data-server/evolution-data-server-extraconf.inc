inherit autotools 
inherit gtk-doc 
inherit pkgconfig 
inherit gettext

export HOST_SYS
export BUILD_SYS
export STAGING_LIBDIR
export STAGING_INCDIR

export B="${S}"

#DEPENDS += "gobject-introspection"
#gtk-doc-stub?

# -ldb needs this on some platforms
LDFLAGS += "-lpthread"

EXTRA_OECONF += "--with-libdb=${STAGING_DIR_HOST}${prefix}"

# Parallel make shows many issues with this source code.
# Current problems seem to be duplicate execution of the calander/backends
# directories by make resulting in truncated/corrupt .la files
#PARALLEL_MAKE = ""

do_compile_prepend() {
    cp ${WORKDIR}/iconv-detect.h ${S}
}


do_install_append() {
    rm -fr ${D}/usr/share/help
}

SRC_URI = " \
    file://iconv-detect.h \
    file://0004-configure-Fix-libical-pkg-config-trying-to-use-host-.patch \
"

FILES_${PN}-dbg += "/usr/lib/evolution-data-server/calendar-backends/.debug"
FILES_${PN}-dbg += "/usr/lib/evolution-data-server/camel-providers/.debug"
FILES_${PN}-dbg += "/usr/lib/evolution-data-server/registry-modules/.debug"
FILES_${PN}-dbg += "/usr/lib/evolution-data-server/addressbook-backends/.debug"
FILES_${PN}-dbg += "/usr/libexec/evolution-data-server/.debug"