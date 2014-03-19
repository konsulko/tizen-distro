DESCRIPTION = "Webkit2 EFL"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Applications/Internet"
LICENSE = "LGPLv2.1 or BSD"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "webkit2-efl-devel"
PACKAGES += "webkit2-efl-test"
PACKAGES += "webkit2-efl"

webkit2-efl-devel_files = ""
webkit2-efl-devel_files += "webkit2-efl.manifest"
webkit2-efl-devel_files += "/usr/include/*"
webkit2-efl-devel_files += "/usr/lib/pkgconfig/*"

webkit2-efl-test_files = ""
webkit2-efl-test_files += "webkit2-efl.manifest"
webkit2-efl-test_files += "/usr/bin/MiniBrowser"

webkit2-efl_files = ""
webkit2-efl_files += "webkit2-efl.manifest"
webkit2-efl_files += "/usr/lib/*.so*"
webkit2-efl_files += "/usr/bin/*"
webkit2-efl_files += "/usr/share/*"

FILES_${PN}-devel = "${webkit2-efl-devel_files}"
FILES_${PN}-test = "${webkit2-efl-test_files}"
FILES_${PN} = "${webkit2-efl_files}"

PKG_webkit2-efl-devel= "webkit2-efl-devel"
PKG_webkit2-efl-test= "webkit2-efl-test"
PKG_webkit2-efl= "webkit2-efl"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require webkit-efl-rdepends.inc
require webkit-efl-depends.inc
require webkit-efl-extraconf.inc
