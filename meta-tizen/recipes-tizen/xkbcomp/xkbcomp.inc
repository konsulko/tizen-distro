DESCRIPTION = "Utility to compile XKB keyboard description"
HOMEPAGE = "http://xorg.freedesktop.org/"
SECTION = "System/X11/Utilities"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "xkbcomp"
PACKAGES += "xkbcomp-devel"

xkbcomp_files = ""
xkbcomp_files += "xkbcomp.manifest"
xkbcomp_files += "COPYING"
xkbcomp_files += "/usr/bin/xkbcomp"
xkbcomp_files += "/usr/share/man/man1/xkbcomp.1.gz"

xkbcomp-devel_files = ""
xkbcomp-devel_files += "xkbcomp.manifest"
xkbcomp-devel_files += "/usr/lib/pkgconfig/xkbcomp.pc"

FILES_${PN} = "${xkbcomp_files}"
FILES_${PN}-devel = "${xkbcomp-devel_files}"

PKG_xkbcomp= "xkbcomp"
PKG_xkbcomp-devel= "xkbcomp-devel"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require xkbcomp-rdepends.inc
require xkbcomp-depends.inc
require xkbcomp-extraconf.inc
