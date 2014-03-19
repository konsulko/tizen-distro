DESCRIPTION = "Utility to configure and test X input devices"
HOMEPAGE = "http://xorg.freedesktop.org/"
SECTION = "System/X11"
LICENSE = "MIT and HPND"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "xinput"

xinput_files = ""
xinput_files += "xinput.manifest"
xinput_files += "/usr/bin/xinput"
xinput_files += "/usr/share/man/man1/xinput.1.gz"

FILES_${PN} = "${xinput_files}"

PKG_xinput= "xinput"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require xinput-rdepends.inc
require xinput-depends.inc
require xinput-extraconf.inc
