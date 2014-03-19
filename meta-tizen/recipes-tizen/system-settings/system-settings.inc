DESCRIPTION = "A System Settings library in Tizen Native API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/API"
LICENSE = "Apache-2.0"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "capi-system-system-settings-devel"
PACKAGES += "capi-system-system-settings"

capi-system-system-settings-devel_files = ""
capi-system-system-settings-devel_files += "capi-system-system-settings-devel.manifest"
capi-system-system-settings-devel_files += "/usr/include/system/*.h"
capi-system-system-settings-devel_files += "/usr/lib/pkgconfig/*.pc"
capi-system-system-settings-devel_files += "/usr/lib/lib*.so"

capi-system-system-settings_files = ""
capi-system-system-settings_files += "capi-system-system-settings.manifest"
capi-system-system-settings_files += "/usr/lib/lib*.so.*"
capi-system-system-settings_files += "/usr/bin/test_system_settings_gui"

FILES_${PN}-devel = "${capi-system-system-settings-devel_files}"
FILES_${PN} = "${capi-system-system-settings_files}"

PKG_capi-system-system-settings-devel= "capi-system-system-settings-devel"
PKG_capi-system-system-settings= "capi-system-system-settings"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require system-settings-rdepends.inc
require system-settings-depends.inc
require system-settings-extraconf.inc
