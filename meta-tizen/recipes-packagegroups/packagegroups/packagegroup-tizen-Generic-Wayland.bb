SUMMARY = "Generic Wayland"
DESCRIPTION = "Generic Wayland"
LICENSE = "MIT"
DEPENDS = "virtual/kernel"
PR = "r1"
inherit packagegroup

PACKAGE_ARCH = "${MACHINE_ARCH}"

RDEPENDS_${PN} = "" 

RDEPENDS_${PN} += "cantarell-fonts"
RDEPENDS_${PN} += "dejavu-fonts"
RDEPENDS_${PN} += "weston"
RDEPENDS_${PN} += "xkeyboard-config"
RDEPENDS_${PN} += "tizen-branding-default"
RDEPENDS_${PN} += "user-session-units"
RDEPENDS_${PN} += "desktop-skin"
