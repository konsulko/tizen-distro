DESCRIPTION = "The Enlightenment window manager"
HOMEPAGE = "http://www.enlightenment.org/"
SECTION = "Graphics/EFL"
LICENSE = "BSD 2-clause"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "enlightenment-locale"
PACKAGES += "enlightenment"
PACKAGES += "enlightenment-devel"

enlightenment-locale_files = ""

enlightenment_files = ""
enlightenment_files += "enlightenment.manifest"
enlightenment_files += "/etc/enlightenment/sysactions.conf"
enlightenment_files += "/usr/bin/enlightenment*"
enlightenment_files += "/usr/lib/enlightenment/*"
enlightenment_files += "/usr/share/enlightenment/*"
enlightenment_files += "/usr/share/xsessions/enlightenment.desktop"
enlightenment_files += "/etc/xdg/menus/enlightenment.menu"
enlightenment_files += "/usr/share/applications/enlightenment_filemanager.desktop"

enlightenment-devel_files = ""
enlightenment-devel_files += "enlightenment.manifest"
enlightenment-devel_files += "/usr/include/enlightenment/*"
enlightenment-devel_files += "/usr/lib/pkgconfig/*.pc"

FILES_${PN}-locale = "${enlightenment-locale_files}"
FILES_${PN} = "${enlightenment_files}"
FILES_${PN}-devel = "${enlightenment-devel_files}"

PKG_enlightenment-locale= "enlightenment-locale"
PKG_enlightenment= "enlightenment"
PKG_enlightenment-devel= "enlightenment-devel"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require enlightenment-rdepends.inc
require enlightenment-depends.inc
require enlightenment-extraconf.inc
