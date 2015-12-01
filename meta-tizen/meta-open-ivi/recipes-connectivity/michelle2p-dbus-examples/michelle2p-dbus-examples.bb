DESCRIPTION = "Michelle 2 Plus Supervisory DBus Examples"
SECTION = "Network"
LICENSE = "Apache-2.0"

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/Apache-2.0;md5=89aea4e17d99a7cacdbeed46a0096b10"

SRC_URI += "file://introspect-api.py"
SRC_URI += "file://m2p-keypad-event.py"
SRC_URI += "file://m2p-keypad-props.py"

DEPENDS = ""
RDEPENDS_${PN} += " python dbus"

do_install() {
  install -d ${D}${bindir}
  install -m 0755 ${WORKDIR}/introspect-api.py ${D}${bindir}
  install -m 0755 ${WORKDIR}/m2p-keypad-event.py ${D}${bindir}
  install -m 0755 ${WORKDIR}/m2p-keypad-props.py ${D}${bindir}
}

FILES_${PN} += "${D}${bindir}/introspect-api.py"
FILES_${PN} += "${D}${bindir}/m2p-keypad-event.py"
FILES_${PN} += "${D}${bindir}/m2p-keypad-props.py"
