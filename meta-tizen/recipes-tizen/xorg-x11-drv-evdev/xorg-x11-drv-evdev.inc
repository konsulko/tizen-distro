DESCRIPTION = "Xorg X11 evdev input driver"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/X Hardware Support"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "xorg-x11-drv-evdev-devel"
PACKAGES += "xorg-x11-drv-evdev"

xorg-x11-drv-evdev-devel_files = ""
xorg-x11-drv-evdev-devel_files += "/usr/include/xorg/evdev-properties.h"
xorg-x11-drv-evdev-devel_files += "/usr/lib/pkgconfig/xorg-evdev.pc"

xorg-x11-drv-evdev_files = ""
xorg-x11-drv-evdev_files += "/input/evdev_drv.so"
xorg-x11-drv-evdev_files += "/usr/share/license/xorg-x11-drv-evdev"

FILES_${PN}-devel = "${xorg-x11-drv-evdev-devel_files}"
FILES_${PN} = "${xorg-x11-drv-evdev_files}"

PKG_xorg-x11-drv-evdev-devel= "xorg-x11-drv-evdev-devel"
PKG_xorg-x11-drv-evdev= "xorg-x11-drv-evdev"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require xorg-x11-drv-evdev-rdepends.inc
require xorg-x11-drv-evdev-depends.inc
require xorg-x11-drv-evdev-extraconf.inc
