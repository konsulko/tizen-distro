DESCRIPTION = "An EFL utility library in SLP C API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Graphics & UI Framework/API"
LICENSE = "Apache-2.0"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "capi-ui-efl-util"
PACKAGES += "capi-ui-efl-util-devel"

capi-ui-efl-util_files = ""
capi-ui-efl-util_files += "capi-ui-efl-util.manifest"
capi-ui-efl-util_files += "/usr/lib/libcapi-ui-efl-util.so.*"

capi-ui-efl-util-devel_files = ""
capi-ui-efl-util-devel_files += "capi-ui-efl-util.manifest"
capi-ui-efl-util-devel_files += "/usr/include/ui/*.h"
capi-ui-efl-util-devel_files += "/usr/lib/pkgconfig/*.pc"
capi-ui-efl-util-devel_files += "/usr/lib/libcapi-ui-efl-util.so"

FILES_${PN} = "${capi-ui-efl-util_files}"
FILES_${PN}-devel = "${capi-ui-efl-util-devel_files}"

PKG_capi-ui-efl-util= "capi-ui-efl-util"
PKG_capi-ui-efl-util-devel= "capi-ui-efl-util-devel"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require efl-util-rdepends.inc
require efl-util-depends.inc
require efl-util-extraconf.inc
