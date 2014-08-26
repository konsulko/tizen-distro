export libexecdir = "${prefix}/libexec"

FILES_${PN}-dbg += "${prefix}/lib/ibus-hangul/setup/.debug/hangul_keyboard_list"

do_install_append() {
 rm -fr ${D}${bindir}
 
}