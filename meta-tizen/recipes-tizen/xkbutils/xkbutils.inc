DESCRIPTION = "Collection of small utilities utilizing the X11 XKeyboard extension"
HOMEPAGE = "http://xorg.freedesktop.org/"
SECTION = "System/X11/Utilities"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "xkbutils-docs"
PACKAGES += "xkbutils"

xkbutils-docs_files = ""
xkbutils-docs_files += "/usr/share/info"
xkbutils-docs_files += "/usr/share/man"

xkbutils_files = ""
xkbutils_files += "xkbutils.manifest"
xkbutils_files += "COPYING"
xkbutils_files += "/usr/bin/xkbbell"
xkbutils_files += "/usr/bin/xkbvleds"
xkbutils_files += "/usr/bin/xkbwatch"

FILES_${PN}-docs = "${xkbutils-docs_files}"
FILES_${PN} = "${xkbutils_files}"

PKG_xkbutils-docs= "xkbutils-docs"
PKG_xkbutils= "xkbutils"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require xkbutils-rdepends.inc
require xkbutils-depends.inc
require xkbutils-extraconf.inc
