SRC_URI += "file://Add_extralib.diff"

do_install_append() {
 rm -fr "${D}${prefix}/bin/pkgcmd.real"
 rm -fr "${D}${prefix}/bin/pkgcmd.wrapper"
}