# Disable everything but the media-export plugin, add the lms plugin
PACKAGECONFIG = "media-export lms"
PACKAGECONFIG[lms] = "--enable-lms-plugin,--disable-lms-plugin,sqlite3"

# LightMediaScanner plugin patches
SRC_URI += "file://0001-Add-LightMediaScanner-plugin.patch \
            file://0002-lms-add-C-source-files.patch \
            file://exit-if-plugins-directory-is-not-found.patch \
            file://rygel.service \
            "

inherit systemd

SYSTEMD_PACKAGES = "${PN}"
SYSTEMD_SERVICE_${PN} = ""
SYSTEMD_SERVICE_${PN} += "rygel.service"

do_install_append() {
       # Install rygel systemd service
       if ${@bb.utils.contains('DISTRO_FEATURES', 'systemd', 'true', 'false', d)}; then
              install -p -D ${WORKDIR}/rygel.service ${D}${systemd_unitdir}/system/rygel.service
       fi
}
