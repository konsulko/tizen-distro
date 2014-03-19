DESCRIPTION = "Utility to display information about an X server"
HOMEPAGE = "http://xorg.freedesktop.org/"
SECTION = "Graphics/Utilities"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "xdpyinfo"

xdpyinfo_files = ""
xdpyinfo_files += "xdpyinfo.manifest"
xdpyinfo_files += "/usr/bin/xdpyinfo"
xdpyinfo_files += "/usr/share/man/man1/xdpyinfo.1.gz"

FILES_${PN} = "${xdpyinfo_files}"

PKG_xdpyinfo= "xdpyinfo"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require xdpyinfo-rdepends.inc
require xdpyinfo-depends.inc
require xdpyinfo-extraconf.inc
