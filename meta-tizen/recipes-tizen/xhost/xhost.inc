DESCRIPTION = "Utility to control X server access"
HOMEPAGE = "http://xorg.freedesktop.org/"
SECTION = "System/X11"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "xhost"

xhost_files = ""
xhost_files += "xhost.manifest"
xhost_files += "/usr/bin/xhost"
xhost_files += "/usr/share/man/man1/xhost.1.gz"

FILES_${PN} = "${xhost_files}"

PKG_xhost= "xhost"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require xhost-rdepends.inc
require xhost-depends.inc
require xhost-extraconf.inc
