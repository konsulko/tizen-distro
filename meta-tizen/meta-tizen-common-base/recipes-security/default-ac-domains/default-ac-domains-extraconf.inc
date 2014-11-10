SRC_URI = "file://default-ac-domains"

do_install () {
 mkdir -p ${D}${sysconfdir}/smack/accesses.d/
 cp ${WORKDIR}/default-ac-domains ${D}${sysconfdir}/smack/accesses.d/
}

FILES_${PN} ="${sysconfdir}/smack/accesses.d/default-ac-domains"
