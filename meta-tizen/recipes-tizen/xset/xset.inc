DESCRIPTION = "User preference utility for X"
HOMEPAGE = "http://xorg.freedesktop.org/"
SECTION = "System/X11"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "xset"

xset_files = ""
xset_files += "xset.manifest"
xset_files += "/usr/bin/xset"
xset_files += "/usr/share/man/man1/xset.1.gz"

FILES_${PN} = "${xset_files}"

PKG_xset= "xset"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require xset-rdepends.inc
require xset-depends.inc
require xset-extraconf.inc
