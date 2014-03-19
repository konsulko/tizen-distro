DESCRIPTION = "X Window System initializer"
HOMEPAGE = "http://xorg.freedesktop.org/"
SECTION = "System/X11/Utilities"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "xinit"

xinit_files = ""
xinit_files += "xinit.manifest"
xinit_files += "/etc/X11/xinit/"
xinit_files += "/usr/bin/xinit"
xinit_files += "/usr/share/man/man1/startx.1.gz"
xinit_files += "/usr/share/man/man1/xinit.1.gz"

FILES_${PN} = "${xinit_files}"

PKG_xinit= "xinit"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require xinit-rdepends.inc
require xinit-depends.inc
require xinit-extraconf.inc
