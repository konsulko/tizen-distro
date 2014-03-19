DESCRIPTION = "Utility to modify keymaps and pointer button mappings in X"
HOMEPAGE = "http://xorg.freedesktop.org/"
SECTION = "System/X11/Utilities"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "xmodmap"

xmodmap_files = ""
xmodmap_files += "xmodmap.manifest"
xmodmap_files += "COPYING"
xmodmap_files += "/etc/X11/Xmodmap"
xmodmap_files += "/etc/X11/Xmodmap.remote"
xmodmap_files += "/usr/bin/xmodmap"
xmodmap_files += "/usr/share/man/man1/xmodmap.1.gz"

FILES_${PN} = "${xmodmap_files}"

PKG_xmodmap= "xmodmap"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require xmodmap-rdepends.inc
require xmodmap-depends.inc
require xmodmap-extraconf.inc
