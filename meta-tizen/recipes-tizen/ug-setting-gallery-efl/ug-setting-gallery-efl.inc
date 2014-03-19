DESCRIPTION = "UG setting gallery ELF"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Applications"
LICENSE = "Flora Software License"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "ug-setting-gallery-efl"

ug-setting-gallery-efl_files = ""
ug-setting-gallery-efl_files += "ug-setting-gallery-efl.manifest"
ug-setting-gallery-efl_files += "/usr/ug/lib/*"
ug-setting-gallery-efl_files += "/usr/ug/res/*"
ug-setting-gallery-efl_files += "/usr/share/license/ug-setting-gallery-efl"

FILES_${PN} = "${ug-setting-gallery-efl_files}"

PKG_ug-setting-gallery-efl= "ug-setting-gallery-efl"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require ug-setting-gallery-efl-rdepends.inc
require ug-setting-gallery-efl-depends.inc
require ug-setting-gallery-efl-extraconf.inc
