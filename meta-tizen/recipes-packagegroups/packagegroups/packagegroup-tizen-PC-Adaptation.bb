SUMMARY = "PC Adaptation"
DESCRIPTION = "PC Adaptation"
LICENSE = "MIT"
DEPENDS = "virtual/kernel"
PR = "r1"
inherit packagegroup

PACKAGE_ARCH = "${MACHINE_ARCH}"

RDEPENDS_${PN} = "" 

RDEPENDS_${PN} += "linux-firmware"
RDEPENDS_${PN} += "kernel-adaptation-pc"
RDEPENDS_${PN} += "xf86-input-synaptics"
RDEPENDS_${PN} += "xf86-video-intel"
RDEPENDS_${PN} += "xf86-input-keyboard"
