SUMMARY = "Applications"
DESCRIPTION = "Applications"
LICENSE = "MIT"
DEPENDS = "virtual/kernel"
PR = "r1"
inherit packagegroup

PACKAGE_ARCH = "${MACHINE_ARCH}"

RDEPENDS_${PN} = "" 

RDEPENDS_${PN} += "xterm"
