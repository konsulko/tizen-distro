SUMMARY = "Graphics and UI Framework X"
DESCRIPTION = "Graphics and UI Framework X"
LICENSE = "MIT"
DEPENDS = "virtual/kernel"
PR = "r1"
inherit packagegroup

PACKAGE_ARCH = "${MACHINE_ARCH}"

RDEPENDS_${PN} = "" 

RDEPENDS_${PN} += "xf86-input-evdev"
RDEPENDS_${PN} += "xf86-input-evdevmultitouch"
RDEPENDS_${PN} += "xkeyboard-config"
RDEPENDS_${PN} += "xorg-launch-helper"
RDEPENDS_${PN} += "xorg-server-setuid"
