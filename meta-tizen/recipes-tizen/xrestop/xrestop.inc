DESCRIPTION = "X Resource Monitor"
HOMEPAGE = "http://www.freedesktop.org/Software/xrestop"
SECTION = "Development/Tools"
LICENSE = "GPL-2.0+"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "xrestop"

xrestop_files = ""
xrestop_files += "xrestop.manifest"
xrestop_files += "/usr/bin/xrestop"

FILES_${PN} = "${xrestop_files}"

PKG_xrestop= "xrestop"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require xrestop-rdepends.inc
require xrestop-depends.inc
require xrestop-extraconf.inc
