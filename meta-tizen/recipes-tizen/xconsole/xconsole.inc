DESCRIPTION = "Utility to monitor system console messages with X"
HOMEPAGE = "http://xorg.freedesktop.org/"
SECTION = "System/X11/Utilities"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "xconsole"

xconsole_files = ""
xconsole_files += "xconsole.manifest"
xconsole_files += "COPYING"
xconsole_files += "/usr/bin/xconsole"
xconsole_files += "/etc/X11/app-defaults/XConsole"
xconsole_files += "/usr/share/man/man1/xconsole.1.gz"

FILES_${PN} = "${xconsole_files}"

PKG_xconsole= "xconsole"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require xconsole-rdepends.inc
require xconsole-depends.inc
require xconsole-extraconf.inc
