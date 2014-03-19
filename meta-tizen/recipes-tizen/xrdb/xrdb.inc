DESCRIPTION = "X server resource database utility"
HOMEPAGE = "http://xorg.freedesktop.org/"
SECTION = "System/X11/Utilities"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "xrdb"

xrdb_files = ""
xrdb_files += "xrdb.manifest"
xrdb_files += "AUTHORS ChangeLog COPYING README"
xrdb_files += "/usr/bin/xrdb"
xrdb_files += "/usr/share/man/man1/xrdb.1.gz"

FILES_${PN} = "${xrdb_files}"

PKG_xrdb= "xrdb"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require xrdb-rdepends.inc
require xrdb-depends.inc
require xrdb-extraconf.inc
