SUMMARY = "Web Framework"
DESCRIPTION = "Web Framework"
LICENSE = "MIT"
DEPENDS = "virtual/kernel"
PR = "r1"
inherit packagegroup

PACKAGE_ARCH = "${MACHINE_ARCH}"

RDEPENDS_${PN} = "" 

RDEPENDS_${PN} += "wrt"
RDEPENDS_${PN} += "wrt-plugins-common"
RDEPENDS_${PN} += "wrt-commons"
RDEPENDS_${PN} += "wrt-security"
RDEPENDS_${PN} += "wrt-installer"
RDEPENDS_${PN} += "webkit2-efl"
