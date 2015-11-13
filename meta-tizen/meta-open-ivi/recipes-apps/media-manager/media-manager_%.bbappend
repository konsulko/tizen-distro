SRC_URI += "file://media-manager.service"

inherit systemd

SYSTEMD_PACKAGES = "${PN}"
SYSTEMD_SERVICE_${PN} = ""
SYSTEMD_SERVICE_${PN} += "media-manager.service"

do_install_append() {
       # Install media-manager systemd service
       if ${@bb.utils.contains('DISTRO_FEATURES', 'systemd', 'true', 'false', d)}; then
              install -p -D ${WORKDIR}/media-manager.service ${D}${systemd_unitdir}/system/media-manager.service
       fi
}
