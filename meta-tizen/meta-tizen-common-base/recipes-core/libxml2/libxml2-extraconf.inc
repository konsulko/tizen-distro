DEPENDS_class-nativesdk = "nativesdk-python"
DEPENDS_class-native = "python-native"
DEPENDS =+ "zlib"

SRC_URI = "file://libxml-64bit.patch \
           file://ansidecl.patch \
           file://run-ptest \
           file://libxml2-CVE-2014-0191-fix.patch \
           file://python-sitepackages-dir.patch \
          "

BINCONFIG = "${bindir}/xml2-config"

#inherit autotools pkgconfig binconfig-disabled pythonnative ptest
inherit  pkgconfig binconfig-disabled pythonnative 

RDEPENDS_${PN}-ptest_append_libc-glibc += "glibc-gconv-ebcdic-us glibc-gconv-ibm1141"

# We don't DEPEND on binutils for ansidecl.h so ensure we don't use the header
do_configure_prepend () {
	sed -i -e '/.*ansidecl.h.*/d' ${S}/configure.in
}

do_configure_prepend_class-nativesdk () {
	# Ensure we get the correct site-packages path
	export PYTHON_SITE_PACKAGES="${PYTHON_SITEPACKAGES_DIR}"
}

do_compile_prepend_class-nativesdk () {
	# Ensure we get the correct site-packages path
	export PYTHON_SITE_PACKAGES="${PYTHON_SITEPACKAGES_DIR}"
}

EXTRA_OECONF += "--without-python "
#EXTRA_OECONF += "--without-python --without-debug --without-legacy --with-catalog --without-docbook --with-c14n --without-lzma --with-fexceptions"

EXTRA_OECONF_class-native += "--with-python=${STAGING_BINDIR}/python "
#EXTRA_OECONF_class-native = "--with-python=${STAGING_BINDIR}/python --without-legacy --without-docbook --with-c14n --without-lzma"

EXTRA_OECONF_class-nativesdk += "--with-python=${STAGING_BINDIR}/python "
#EXTRA_OECONF_class-nativesdk = "--with-python=${STAGING_BINDIR}/python --without-legacy --without-docbook --with-c14n --without-lzma"

EXTRA_OECONF_linuxstdbase += "--without-python "
#EXTRA_OECONF_linuxstdbase = "--without-python --with-debug --with-legacy --with-docbook --with-c14n --without-lzma"

# required for pythong binding
export HOST_SYS
export BUILD_SYS
export STAGING_LIBDIR
export STAGING_INCDIR

export LDFLAGS += "-ldl"

python populate_packages_prepend () {
    # autonamer would call this libxml2-2, but we don't want that
    if d.getVar('DEBIAN_NAMES', True):
        d.setVar('PKG_libxml2', '${MLPREFIX}libxml2')
}

PACKAGES += "${PN}-utils ${PN}-python"

FILES_${PN}-dbg += "${PYTHON_SITEPACKAGES_DIR}/.debug"
FILES_${PN}-staticdev += "${PYTHON_SITEPACKAGES_DIR}/*.a"
#FILES_${PN}-dev += "${libdir}/xml2Conf.sh"
#FILES_${PN}-utils += "${bindir}/*"
FILES_${PN}-python += "${PYTHON_SITEPACKAGES_DIR}"

#do_install_ptest () {
#  cp -r ${WORKDIR}/xmlconf ${D}${PTEST_PATH}
#}

BBCLASSEXTEND = "native nativesdk"