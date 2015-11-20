DESCRIPTION = "Michelle 2 Plus Supervisory DBus Network services"
SECTION = "Network"
LICENSE = "Apache-2.0"

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/Apache-2.0;md5=89aea4e17d99a7cacdbeed46a0096b10"

SRC_URI += "file://slip.service"
SRC_URI += "file://supervisor.service"
SRC_URI += "file://supervisor.conf"

inherit allarch systemd

DEPENDS = ""
RDEPENDS_${PN} += " systemd net-tools dbus"

SYSTEMD_PACKAGES = "${PN}"
SYSTEMD_SERVICE_${PN} += " slip.service supervisor.service"

do_install() {
  install -d ${D}${systemd_unitdir}/system
  install -m 0644 ${WORKDIR}/slip.service ${D}${systemd_unitdir}/system
  install -m 0644 ${WORKDIR}/supervisor.service ${D}${systemd_unitdir}/system
  install -d ${D}${sysconfdir}/dbus-1
  install -m 0644 ${WORKDIR}/supervisor.conf ${D}${sysconfdir}/dbus-1
}

FILES_${PN} += "${D}${sysconfdir}/dbus-1/supervisor.conf"
