SUMMARY = "Generic X11"
DESCRIPTION = "Generic X11"
LICENSE = "MIT"
DEPENDS = "virtual/kernel"
PR = "r1"
inherit packagegroup

PACKAGE_ARCH = "${MACHINE_ARCH}"

RDEPENDS_${PN} = "" 

RDEPENDS_${PN} += "xorg-server"
RDEPENDS_${PN} += "xf86-input-synaptics"
RDEPENDS_${PN} += "xf86-video-intel"
RDEPENDS_${PN} += "xf86-input-keyboard"
