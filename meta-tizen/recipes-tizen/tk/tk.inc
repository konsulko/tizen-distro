DESCRIPTION = "Graphical User Interface Toolkit for Tcl"
HOMEPAGE = "http://www.tcl.tk"
SECTION = "Development/Languages"
LICENSE = "BSD-3-Clause"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "tk-devel"
PACKAGES += "tk"

tk-devel_files = ""
tk-devel_files += "/usr/share/man/man3/*"
tk-devel_files += "/usr/include/*"
tk-devel_files += "/usr/lib64/tcl/tk8.6/tkAppInit.c"
tk-devel_files += "/usr/lib/tkConfig.sh"
tk-devel_files += "/usr/lib/pkgconfig/*"

tk_files = ""
tk_files += "/usr/share/man/man1/*"
tk_files += "/usr/share/man/mann/*"
tk_files += "/usr/bin/*"
tk_files += "/usr/lib/*.so"
tk_files += "/usr/lib64/tcl/tk8.6"

FILES_${PN}-devel = "${tk-devel_files}"
FILES_${PN} = "${tk_files}"

PKG_tk-devel= "tk-devel"
PKG_tk= "tk"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require tk-rdepends.inc
require tk-depends.inc
require tk-extraconf.inc
