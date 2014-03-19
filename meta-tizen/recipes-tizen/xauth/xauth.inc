DESCRIPTION = "Utility to edit and display the X authorization information"
HOMEPAGE = "http://xorg.freedesktop.org/"
SECTION = "System/X11/Utilities"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "xauth"

xauth_files = ""
xauth_files += "xauth.manifest"
xauth_files += "COPYING"
xauth_files += "/usr/bin/xauth"
xauth_files += "/usr/share/man/man1/xauth.1.gz"

FILES_${PN} = "${xauth_files}"

PKG_xauth= "xauth"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require xauth-rdepends.inc
require xauth-depends.inc
require xauth-extraconf.inc
