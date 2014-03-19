DESCRIPTION = "Utility to list interned atoms defined on an X11 server"
HOMEPAGE = "http://xorg.freedesktop.org/"
SECTION = "Graphics/Utilities"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "xlsatoms"

xlsatoms_files = ""
xlsatoms_files += "xlsatoms.manifest"
xlsatoms_files += "/usr/bin/xlsatoms"
xlsatoms_files += "/usr/share/man/man1/xlsatoms.1.gz"

FILES_${PN} = "${xlsatoms_files}"

PKG_xlsatoms= "xlsatoms"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require xlsatoms-rdepends.inc
require xlsatoms-depends.inc
require xlsatoms-extraconf.inc
