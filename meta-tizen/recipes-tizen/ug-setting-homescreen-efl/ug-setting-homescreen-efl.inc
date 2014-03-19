DESCRIPTION = "UI Gadget : setting-homescreen-efl"
HOMEPAGE = "http://nohomepage.org"
SECTION = "misc"
LICENSE = "Flora License"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "ug-setting-homescreen-efl"

ug-setting-homescreen-efl_files = ""
ug-setting-homescreen-efl_files += "ug-setting-homescreen-efl.manifest"
ug-setting-homescreen-efl_files += "/etc/smack/accesses2.d/ug.setting-homescreen-efl.include"
ug-setting-homescreen-efl_files += "/usr/ug/lib/*"
ug-setting-homescreen-efl_files += "/usr/ug/res/*"

FILES_${PN} = "${ug-setting-homescreen-efl_files}"

PKG_ug-setting-homescreen-efl= "ug-setting-homescreen-efl"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require ug-setting-homescreen-efl-rdepends.inc
require ug-setting-homescreen-efl-depends.inc
require ug-setting-homescreen-efl-extraconf.inc
