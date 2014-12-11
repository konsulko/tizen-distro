SECTION = "Security/Crypto Libraries"

do_compile_prepend_class-native() {
    export LD_LIBS="${LDFLAGS}"
}

do_install_append_class-native() {
    # Create empty .chk files for the NSS libraries at build time. They could
    # be regenerated at target's boot time.
    for file in libsoftokn3.chk libfreebl3.chk libnssdbm3.chk; do
        touch ${D}/${libdir}/$file
        chmod 755 ${D}/${libdir}/$file
    done
    install -D -m 755 ${WORKDIR}/signlibs.sh ${D}/${bindir}/signlibs.sh

    install -d ${D}${libdir}/pkgconfig/
    sed 's/%NSS_VERSION%/${PV}/' ${WORKDIR}/nss.pc.in | sed 's/%NSPR_VERSION%/4.9.2/' > ${D}${libdir}/pkgconfig/nss.pc
    sed -i s:OEPREFIX:${prefix}:g ${D}${libdir}/pkgconfig/nss.pc
    sed -i s:OEEXECPREFIX:${exec_prefix}:g ${D}${libdir}/pkgconfig/nss.pc
    sed -i s:OELIBDIR:${libdir}:g ${D}${libdir}/pkgconfig/nss.pc
    sed -i s:OEINCDIR:${includedir}/nss3:g ${D}${libdir}/pkgconfig/nss.pc
}

SRC_URI_append_class-native = "\
    file://nss.pc.in \
    file://signlibs.sh \
"

FILES_${PN}-dbg += "\
    ${bindir}/.debug/* \
    ${libdir}/.debug/* \
    ${libdir}/debug/* \
    "