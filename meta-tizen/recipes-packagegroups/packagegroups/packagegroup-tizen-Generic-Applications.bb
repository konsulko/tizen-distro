SUMMARY = "Generic Applications"
DESCRIPTION = "Generic Applications"
LICENSE = "MIT"
DEPENDS = "virtual/kernel"
PR = "r1"
inherit packagegroup

PACKAGE_ARCH = "${MACHINE_ARCH}"

RDEPENDS_${PN} = "" 

RDEPENDS_${PN} += "ail"
RDEPENDS_${PN} += "ca-certificates"
RDEPENDS_${PN} += "webkit2-efl-test"
