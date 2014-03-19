DESCRIPTION = "Primitive command line interface to RandR extension"
HOMEPAGE = "http://xorg.freedesktop.org/"
SECTION = "Graphics/X Window System"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "xrandr"

xrandr_files = ""
xrandr_files += "xrandr.manifest"
xrandr_files += "/usr/bin/xrandr"
xrandr_files += "/usr/share/man/man1/xrandr.1.gz"

FILES_${PN} = "${xrandr_files}"

PKG_xrandr= "xrandr"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require xrandr-rdepends.inc
require xrandr-depends.inc
require xrandr-extraconf.inc
