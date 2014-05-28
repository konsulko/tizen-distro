SUMMARY = "default-ac-domains"
DESCRIPTION = "The definition of default ac domains"
SECTION = "base"
PR = "1"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"


SRC_URI = "file://default-ac-domains"

do_install () {
 mkdir -p ${D}${sysconfdir}/smack/accesses.d/
 cp ${WORKDIR}/default-ac-domains ${D}${sysconfdir}/smack/accesses.d/
}


FILES_${PN} ="${sysconfdir}/smack/accesses.d/default-ac-domains"