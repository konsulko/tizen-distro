do_install_append() {
    rm -fr ${D}${systemd_unitdir}/user
    rm ${D}/usr/lib/libmurphy-plugin-system-monitor*
}

FILES_${PN}-dev += " /usr/include/murphy" 
FILES_${PN}-dbg += " /usr/lib/murphy/plugins/.debug"

murphy-doc_files = ""
murphy-doc_files += "${prefix}/share/doc/murphy/AUTHORS"
murphy-doc_files += "${prefix}/share/doc/murphy/CODING-STYLE"
murphy-doc_files += "${prefix}/share/doc/murphy/ChangeLog"
murphy-doc_files += "${prefix}/share/doc/murphy/NEWS"
murphy-doc_files += "${prefix}/share/doc/murphy/README"
