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


BBCLASSEXTEND += " native "

PROVIDES = ""
PROVIDES += "openivi-installer-xwalk"
PROVIDES += "openivi-installer-wrt"

RDEPENDS = ""
RDEPENDS_${PN}-xwalk += "openivi-homescreen"
RDEPENDS_${PN}-xwalk += "openivi-browser"
RDEPENDS_${PN}-xwalk += "openivi-maps"
RDEPENDS_${PN}-xwalk += "openivi-dashboard"
RDEPENDS_${PN}-xwalk += "openivi-media-manager-app"
RDEPENDS_${PN}-xwalk += "openivi-hvac"
RDEPENDS_${PN}-xwalk += "config-open-ivi"
RDEPENDS_${PN}-xwalk += "tizen-platform-config"
RDEPENDS_${PN}-xwalk += "crosswalk"

RDEPENDS_${PN}-wrt += "wrt-installer"
RDEPENDS_${PN}-wrt_remove = "wrt-installer"

DEPENDS = ""

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
}

do_configure() {
}

do_compile() {
}

do_install() {
    install -m 0755 -p -D ${WORKDIR}/openivi-installer-postinst.sh ${D}${prefix}/share/openivi-installer/openivi-installer-postinst.sh
    install -p -D ${WORKDIR}/openivi-installer-postinst.service ${D}${systemd_unitdir}/system/openivi-installer-postinst.service
    mkdir -p ${D}${systemd_unitdir}/system/multi-user.target.wants
    ln -sf ../openivi-installer-postinst.service ${D}${systemd_unitdir}/system/multi-user.target.wants/openivi-installer-postinst.service
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " openivi-installer-xwalk "
PACKAGES += " openivi-installer-wrt "

openivi-installer-xwalk_files = ""
MANIFESTFILES_${PN}-xwalk = "openivi-installer.manifest"

openivi-installer-wrt_files = ""
MANIFESTFILES_${PN}-wrt = "openivi-installer.manifest"

FILES_${PN}-xwalk = "${openivi-installer-xwalk_files}"
FILES_${PN}-xwalk += "${prefix}/share/openivi-installer/openivi-installer-postinst.sh"
FILES_${PN}-xwalk += "${systemd_unitdir}/system/openivi-installer-postinst.service"
FILES_${PN}-xwalk += "${systemd_unitdir}/system/multi-user.target.wants/openivi-installer-postinst.service"
FILES_${PN}-wrt = "${openivi-installer-wrt_files}"


PKG_openivi-installer-xwalk= "openivi-installer-xwalk"
PKG_openivi-installer-wrt= "openivi-installer-wrt"
