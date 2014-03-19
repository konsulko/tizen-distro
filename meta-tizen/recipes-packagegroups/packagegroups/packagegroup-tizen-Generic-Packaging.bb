SUMMARY = "Generic Packaging"
DESCRIPTION = "Generic Packaging"
LICENSE = "MIT"
DEPENDS = "virtual/kernel"
PR = "r1"
inherit packagegroup

PACKAGE_ARCH = "${MACHINE_ARCH}"

RDEPENDS_${PN} = "" 

RDEPENDS_${PN} += "gpg2"
RDEPENDS_${PN} += "zypper"
