DESCRIPTION = "Edbus python bindings"
HOMEPAGE = "http://www.enlightenment.org"
SECTION = "EFL"
LICENSE = "LGPL2.1"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "python-elementary"
PACKAGES += "python-elementary-devel"

python-elementary_files = ""
python-elementary_files += "python-elementary.manifest"
python-elementary_files += "/usr/lib/python2.7/site-packages/elementary"

python-elementary-devel_files = ""
python-elementary-devel_files += "python-elementary.manifest"
python-elementary-devel_files += "/usr/share/python-elementary/examples"
python-elementary-devel_files += "/usr/lib/pkgconfig/*.pc"

FILES_${PN} = "${python-elementary_files}"
FILES_${PN}-devel = "${python-elementary-devel_files}"

PKG_python-elementary= "python-elementary"
PKG_python-elementary-devel= "python-elementary-devel"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require python-elementary-rdepends.inc
require python-elementary-depends.inc
require python-elementary-extraconf.inc
