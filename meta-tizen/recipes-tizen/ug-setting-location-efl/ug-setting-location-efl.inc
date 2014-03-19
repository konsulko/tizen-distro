DESCRIPTION = "UG setting location EFL"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Flora Software License"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "ug-setting-location-efl"

ug-setting-location-efl_files = ""
ug-setting-location-efl_files += "ug-setting-location-efl.manifest"
ug-setting-location-efl_files += "/usr/ug/lib/libug-setting-location-efl.so*"
ug-setting-location-efl_files += "/usr/share/packages/ug-setting-location-efl.xml"
ug-setting-location-efl_files += "/usr/ug/res/edje/ug-setting-location-efl/setting-location.edj"
ug-setting-location-efl_files += "/usr/ug/res/locale/*"

FILES_${PN} = "${ug-setting-location-efl_files}"

PKG_ug-setting-location-efl= "ug-setting-location-efl"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require ug-setting-location-efl-rdepends.inc
require ug-setting-location-efl-depends.inc
require ug-setting-location-efl-extraconf.inc
