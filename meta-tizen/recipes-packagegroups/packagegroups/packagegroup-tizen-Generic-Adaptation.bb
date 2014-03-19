SUMMARY = "Generic Adaptation"
DESCRIPTION = "Generic Adaptation"
LICENSE = "MIT"
DEPENDS = "virtual/kernel"
PR = "r1"
inherit packagegroup

PACKAGE_ARCH = "${MACHINE_ARCH}"

RDEPENDS_${PN} = "" 

RDEPENDS_${PN} += "linux-firmware"
RDEPENDS_${PN} += "kernel-x86-generic"
RDEPENDS_${PN} += "dlogutil"
RDEPENDS_${PN} += "system-installer"
