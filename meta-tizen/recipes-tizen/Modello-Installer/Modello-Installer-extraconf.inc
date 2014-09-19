SRC_URI += "file://modello-installer-postinst.sh"
SRC_URI += "file://modello-installer-postinst.service"

RDEPENDS_Modello_Installer-xwalk_remove = "Modello_Phone"

do_install_append() {
    install -m 0755 -p -D ${WORKDIR}/modello-installer-postinst.sh ${D}${prefix}/share/modello-installer/modello-installer-postinst.sh
    install -p -D ${WORKDIR}/modello-installer-postinst.service ${D}/lib/systemd/system/modello-installer-postinst.service
    mkdir -p ${D}/lib/systemd/system/multi-user.target.wants
    ln -sf ../modello-installer-postinst.service ${D}/lib/systemd/system/multi-user.target.wants/modello-installer-postinst.service
}

FILES_Modello_Installer-xwalk += "${prefix}/share/modello-installer/modello-installer-postinst.sh"
FILES_Modello_Installer-xwalk += "/lib/systemd/system/modello-installer-postinst.service"
FILES_Modello_Installer-xwalk += "/lib/systemd/system/multi-user.target.wants/modello-installer-postinst.service"
