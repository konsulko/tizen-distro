DESCRIPTION = "Utility to set X root window parameter"
HOMEPAGE = "http://xorg.freedesktop.org/"
SECTION = "System/X11/Utilities"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "xsetroot"

xsetroot_files = ""
xsetroot_files += "xsetroot.manifest"
xsetroot_files += "COPYING README"
xsetroot_files += "/usr/bin/xsetroot"
xsetroot_files += "/usr/share/man/man1/xsetroot.1.gz"

FILES_${PN} = "${xsetroot_files}"

PKG_xsetroot= "xsetroot"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require xsetroot-rdepends.inc
require xsetroot-depends.inc
require xsetroot-extraconf.inc
