DESCRIPTION = "XKB event daemon"
HOMEPAGE = "http://xorg.freedesktop.org/"
SECTION = "System/X11/Utilities"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "xkbevd"

xkbevd_files = ""
xkbevd_files += "xkbevd.manifest"
xkbevd_files += "COPYING"
xkbevd_files += "/usr/bin/xkbevd"
xkbevd_files += "/usr/share/man/man1/xkbevd.1.gz"

FILES_${PN} = "${xkbevd_files}"

PKG_xkbevd= "xkbevd"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require xkbevd-rdepends.inc
require xkbevd-depends.inc
require xkbevd-extraconf.inc
