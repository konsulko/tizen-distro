SRC_URI += "file://modello-installer-postinst.sh"
SRC_URI += "file://modello-installer-postinst.service"

RDEPENDS_Modello_Installer-xwalk_remove = "Modello_Phone"
systemd_unitdir = "/usr/lib/systemd"

RDEPENDS_${PN}-wrt_remove = "wrt-installer"

do_install_append() {
    install -m 0755 -p -D ${WORKDIR}/modello-installer-postinst.sh ${D}${prefix}/share/modello-installer/modello-installer-postinst.sh
    install -p -D ${WORKDIR}/modello-installer-postinst.service ${D}${systemd_unitdir}/system/modello-installer-postinst.service
    mkdir -p ${D}${systemd_unitdir}/system/multi-user.target.wants
    ln -sf ../modello-installer-postinst.service ${D}${systemd_unitdir}/system/multi-user.target.wants/modello-installer-postinst.service
}

FILES_Modello_Installer-xwalk += "${prefix}/share/modello-installer/modello-installer-postinst.sh"
FILES_Modello_Installer-xwalk += "${systemd_unitdir}/system/modello-installer-postinst.service"
FILES_Modello_Installer-xwalk += "${systemd_unitdir}/system/multi-user.target.wants/modello-installer-postinst.service"
