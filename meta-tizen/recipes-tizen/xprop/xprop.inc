DESCRIPTION = "Property displayer for X"
HOMEPAGE = "http://xorg.freedesktop.org/"
SECTION = "Graphics/Utilities"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "xprop"

xprop_files = ""
xprop_files += "xprop.manifest"
xprop_files += "/usr/bin/xprop"
xprop_files += "/usr/share/man/man1/xprop.1.gz"

FILES_${PN} = "${xprop_files}"

PKG_xprop= "xprop"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require xprop-rdepends.inc
require xprop-depends.inc
require xprop-extraconf.inc
