DESCRIPTION = "Utility to change the keyboard layout in X"
HOMEPAGE = "http://xorg.freedesktop.org/"
SECTION = "System/X11/Utilities"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "setxkbmap"

setxkbmap_files = ""
setxkbmap_files += "setxkbmap.manifest"
setxkbmap_files += "COPYING"
setxkbmap_files += "/usr/bin/setxkbmap"
setxkbmap_files += "/usr/share/man/man1/setxkbmap.1.gz"

FILES_${PN} = "${setxkbmap_files}"

PKG_setxkbmap= "setxkbmap"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require setxkbmap-rdepends.inc
require setxkbmap-depends.inc
require setxkbmap-extraconf.inc
