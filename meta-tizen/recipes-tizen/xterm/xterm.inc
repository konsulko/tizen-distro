DESCRIPTION = "The basic X terminal program"
HOMEPAGE = "http://invisible-island.net/xterm/"
SECTION = "System/X11/Utilities"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "xterm"

xterm_files = ""
xterm_files += "xterm.manifest"
xterm_files += "README README.i18n "
xterm_files += "/usr/bin/vttest"
xterm_files += "/usr/bin/luitx"
xterm_files += "/usr/bin/resize"
xterm_files += "/usr/bin/uxterm"
xterm_files += "/usr/bin/koi8rxterm"
xterm_files += "/usr/bin/Backarrow2Delete"
xterm_files += "/usr/bin/Backarrow2BackSpace"
xterm_files += "/usr/share/man/man1/xterm.1.gz"
xterm_files += "/usr/share/man/man1/resize.1.gz"
xterm_files += "/usr/share/man/man1/vttest.1.gz"
xterm_files += "/usr/share/man/man1/koi8rxterm.1.gz"
xterm_files += "/usr/share/man/man1/uxterm.1.gz"
xterm_files += "/usr/share/applications/xterm.desktop"
xterm_files += "/usr/share/pixmaps/*"
xterm_files += "/usr/lib/X11/etc"
xterm_files += "/usr/lib/X11/etc/xterm.termcap"
xterm_files += "/usr/lib/X11/etc/xterm.terminfo"
xterm_files += "/usr/share/fonts/misc"
xterm_files += "/usr/share/fonts/misc/20x20ja.pcf.gz"
xterm_files += "/usr/share/fonts/misc/20x20ko.pcf.gz"
xterm_files += "/usr/share/X11/app-defaults/KOI8RXTerm"
xterm_files += "/usr/share/X11/app-defaults/KOI8RXTerm-color"
xterm_files += "/usr/share/X11/app-defaults/UXTerm"
xterm_files += "/usr/share/X11/app-defaults/UXTerm-color"
xterm_files += "/usr/share/X11/app-defaults/XTerm"
xterm_files += "/usr/share/X11/app-defaults/XTerm-color"

FILES_${PN} = "${xterm_files}"

PKG_xterm= "xterm"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require xterm-rdepends.inc
require xterm-depends.inc
require xterm-extraconf.inc
