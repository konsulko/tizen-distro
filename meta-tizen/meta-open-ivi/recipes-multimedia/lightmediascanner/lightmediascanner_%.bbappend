# Disable everything but the roygalty-free formats
PACKAGECONFIG = "ogg flac wave m3u pls jpeg png"

FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

SRC_URI += "file://lightmediascanner.service"

inherit systemd

SYSTEMD_PACKAGES = "${PN}"
SYSTEMD_SERVICE_${PN} = ""
SYSTEMD_SERVICE_${PN} += "lightmediascanner.service"

do_install_append() {
       # Install LMS systemd service
       if ${@bb.utils.contains('DISTRO_FEATURES', 'systemd', 'true', 'false', d)}; then
              install -p -D ${WORKDIR}/lightmediascanner.service ${D}${systemd_unitdir}/system/lightmediascanner.service
       fi
}
