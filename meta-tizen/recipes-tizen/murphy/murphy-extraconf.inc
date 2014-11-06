#We should deseable PARALLEL_MAKE only for install
PARALLEL_MAKE = ""

do_install_append() {
    rm -fr ${D}${prefix}/lib/systemd/user
    rm ${D}/usr/lib/libmurphy-plugin-system-monitor*

    if ${@bb.utils.contains('SYS_CTLR_PROVIDER', 'murphy', 'false', 'true', d)}; then
      rm ${D}${prefix}/lib/murphy/plugins/plugin-system-controller.so
      rm ${D}${prefix}/lib/systemd/user/ico-homescreen.service
      rm ${D}${prefix}/lib/systemd/user/murphy-wait-for-launchpad-ready.path
    fi
}

FILES_${PN}-dev += " ${prefix}/include/murphy" 
FILES_${PN}-dbg += " ${prefix}/lib/murphy/plugins/.debug"

murphy-doc_files = ""
murphy-doc_files += "${prefix}/share/doc/murphy/AUTHORS"
murphy-doc_files += "${prefix}/share/doc/murphy/CODING-STYLE"
murphy-doc_files += "${prefix}/share/doc/murphy/ChangeLog"
murphy-doc_files += "${prefix}/share/doc/murphy/NEWS"
murphy-doc_files += "${prefix}/share/doc/murphy/README"

PROVIDES_remove := "${@bb.utils.contains('SYS_CTLR_PROVIDER', 'murphy','',"system-controller",d)}"
RPROVIDES_ico-uxf-homescreen-system-controller_remove :=  "${@bb.utils.contains('SYS_CTLR_PROVIDER', 'murphy','',"system-controller",d)}"
