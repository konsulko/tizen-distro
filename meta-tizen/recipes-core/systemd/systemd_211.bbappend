FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

DEPENDS += "smack"
RDEPENDS_${PN} += "smack"

DEPENDS += "attr"

EXTRA_OECONF +=  ' --enable-smack '