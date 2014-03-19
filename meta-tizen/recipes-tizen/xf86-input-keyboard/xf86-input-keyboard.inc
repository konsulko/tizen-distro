DESCRIPTION = "Keyboard input driver for the Xorg X server"
HOMEPAGE = "http://xorg.freedesktop.org/"
SECTION = "System/X11/Servers/XF86_4"
LICENSE = "GPL-2.0+"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "xf86-input-keyboard"

xf86-input-keyboard_files = ""
xf86-input-keyboard_files += "xf86-input-keyboard.manifest"
xf86-input-keyboard_files += "COPYING"
xf86-input-keyboard_files += "/usr/lib/xorg/modules/input"
xf86-input-keyboard_files += "/usr/lib/xorg/modules/input/kbd_drv.so"

FILES_${PN} = "${xf86-input-keyboard_files}"

PKG_xf86-input-keyboard= "xf86-input-keyboard"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require xf86-input-keyboard-rdepends.inc
require xf86-input-keyboard-depends.inc
require xf86-input-keyboard-extraconf.inc
