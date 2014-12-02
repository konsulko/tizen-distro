PARALLEL_MAKE = ""

SRC_URI += "file://remove_doc.patch"

INSANE_SKIP_${PN} = "dev-deps"

do_prep_prepend() {
 CIRDIR=$(pwd)
 cd ${S}/../
 ln -sf ${S} ${PN}-${PV}
 cd ${CIRDIR}
}

do_install_prepend() {
 touch ${S}/doc/festival.1
 touch ${S}/doc/festival_client.1
 touch ${S}/doc/text2wave.1
}
