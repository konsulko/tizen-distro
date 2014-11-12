inherit pkgconfig

EXTRA_OECONF = " --with-pic --disable-vapigen"

SRC_URI += " file://0001-git-version-gen-don-t-append-dirty-if-we-re-not-in-g.patch"
SRC_URI += " file://Fix-time-stamp.patch"

RDEPENDS_${PN}_remove_class-native = "update-alternatives-native"

DEPENDS_append_class-target = " vala-native"

do_install_append() {
 rm -rf ${D}${prefix}/share/devhelp
}

vala_files += "${prefix}/bin/vala"
vala_files += "${prefix}/bin/valac"
vala_files += "${prefix}/bin/vala-gen-introspect"
vala_files += "${prefix}/bin/vapicheck"
vala_files += "${prefix}/bin/vapigen"
vala_files += "${mandir}/man1/valac.1*"
vala_files += "${mandir}/man1/vala-gen-introspect.1*"
vala_files += "${mandir}/man1/vapigen.1*"

FILES_${PN}-dbg += "${prefix}/lib/vala-0.24/.debug"
vala_files += "${prefix}/share/pkgconfig/vapigen.pc"
