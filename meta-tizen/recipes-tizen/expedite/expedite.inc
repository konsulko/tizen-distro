DESCRIPTION = "Evas benchmark/test suite"
HOMEPAGE = "http://www.enlightenment.org/"
SECTION = "Graphics/EFL"
LICENSE = "BSD"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "expedite"

expedite_files = ""
expedite_files += "expedite.manifest"
expedite_files += "/usr/bin/*"
expedite_files += "/usr/share/expedite/*"

FILES_${PN} = "${expedite_files}"

PKG_expedite= "expedite"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require expedite-rdepends.inc
require expedite-depends.inc
require expedite-extraconf.inc
