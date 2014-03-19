SUMMARY = "Enlightenment"
DESCRIPTION = "Enlightenment"
LICENSE = "MIT"
DEPENDS = "virtual/kernel"
PR = "r1"
inherit packagegroup

PACKAGE_ARCH = "${MACHINE_ARCH}"

RDEPENDS_${PN} = "" 

RDEPENDS_${PN} += "enlightenment"
RDEPENDS_${PN} += "econnman"
RDEPENDS_${PN} += "terminology"
RDEPENDS_${PN} += "tizen-branding-default"
RDEPENDS_${PN} += "user-session-units-enlightenment"
