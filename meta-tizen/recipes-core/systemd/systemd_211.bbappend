FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

SRC_URI += "file://0001-Fix-use_smack-corrupt-cached-result.patch"

DEPENDS += "smack"
RDEPENDS_${PN} += "smack"

DEPENDS += "attr"

EXTRA_OECONF +=  ' --enable-smack --with-smack-run-label=System '