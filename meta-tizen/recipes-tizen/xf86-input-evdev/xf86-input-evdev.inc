DESCRIPTION = "Generic Linux input driver for the Xorg X server"
HOMEPAGE = "http://xorg.freedesktop.org/"
SECTION = "System/X11/Servers/XF86_4"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "xf86-input-evdev-devel"
PACKAGES += "xf86-input-evdev"

xf86-input-evdev-devel_files = ""
xf86-input-evdev-devel_files += "xf86-input-evdev.manifest"
xf86-input-evdev-devel_files += "/usr/include/xorg/evdev-properties.h"
xf86-input-evdev-devel_files += "/usr/lib/pkgconfig/xorg-evdev.pc"

xf86-input-evdev_files = ""
xf86-input-evdev_files += "xf86-input-evdev.manifest"
xf86-input-evdev_files += "COPYING"
xf86-input-evdev_files += "/etc/X11/xorg.conf.d/10-evdev.conf"
xf86-input-evdev_files += "/usr/lib/xorg/modules/input"
xf86-input-evdev_files += "/usr/lib/xorg/modules/input/evdev_drv.so"

FILES_${PN}-devel = "${xf86-input-evdev-devel_files}"
FILES_${PN} = "${xf86-input-evdev_files}"

PKG_xf86-input-evdev-devel= "xf86-input-evdev-devel"
PKG_xf86-input-evdev= "xf86-input-evdev"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require xf86-input-evdev-rdepends.inc
require xf86-input-evdev-depends.inc
require xf86-input-evdev-extraconf.inc
