DESCRIPTION = "Utility to print an XKB keyboard description"
HOMEPAGE = "http://xorg.freedesktop.org/"
SECTION = "System/X11/Utilities"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "xkbprint-docs"
PACKAGES += "xkbprint"

xkbprint-docs_files = ""
xkbprint-docs_files += "/usr/share/info"
xkbprint-docs_files += "/usr/share/man"

xkbprint_files = ""
xkbprint_files += "xkbprint.manifest"
xkbprint_files += "COPYING"
xkbprint_files += "/usr/bin/xkbprint"

FILES_${PN}-docs = "${xkbprint-docs_files}"
FILES_${PN} = "${xkbprint_files}"

PKG_xkbprint-docs= "xkbprint-docs"
PKG_xkbprint= "xkbprint"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require xkbprint-rdepends.inc
require xkbprint-depends.inc
require xkbprint-extraconf.inc
