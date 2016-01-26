DESCRIPTION = "Installer for apps"
HOMEPAGE = "http://nohomepage.org"
SECTION = "OpenIVI"
LICENSE = "Apache-2.0"
PR = "r0"

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/Apache-2.0;md5=89aea4e17d99a7cacdbeed46a0096b10"

SRC_URI = ""
SRC_URI += "file://openivi-installer-postinst.sh"
SRC_URI += "file://openivi-installer-postinst.service"

inherit systemd

BBCLASSEXTEND += " native "

RDEPENDS = ""
RDEPENDS_${PN} += "openivi-homescreen"
RDEPENDS_${PN} += "openivi-browser"
RDEPENDS_${PN} += "openivi-maps"
RDEPENDS_${PN} += "openivi-dashboard"
RDEPENDS_${PN} += "openivi-media-manager-app"
RDEPENDS_${PN} += "openivi-hvac"
RDEPENDS_${PN} += "config-open-ivi"
RDEPENDS_${PN} += "tizen-platform-config"
RDEPENDS_${PN} += "crosswalk"

DEPENDS = ""

SYSTEMD_PACKAGES = "${PN}"
SYSTEMD_SERVICE_${PN} = ""
SYSTEMD_SERVICE_${PN} += "openivi-installer-postinst.service"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
}

do_configure() {
}

do_compile() {
}

do_install() {
 if ${@bb.utils.contains('DISTRO_FEATURES', 'systemd', 'true', 'false', d)}; then
  install -m 0755 -p -D ${WORKDIR}/openivi-installer-postinst.sh ${D}${prefix}/share/openivi-installer/openivi-installer-postinst.sh
  install -p -D ${WORKDIR}/openivi-installer-postinst.service ${D}${systemd_unitdir}/system/openivi-installer-postinst.service
 fi
}

FILES_${PN} += "${prefix}/share/openivi-installer/openivi-installer-postinst.sh"
