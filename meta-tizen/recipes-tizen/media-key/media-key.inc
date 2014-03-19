DESCRIPTION = "A System Information library in SLP C API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/API"
LICENSE = "Apache-2.0"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "capi-system-media-key"
PACKAGES += "capi-system-media-key-devel"

capi-system-media-key_files = ""
capi-system-media-key_files += "capi-system-media-key.manifest"
capi-system-media-key_files += "/usr/lib/libcapi-system-media-key.so.*"
capi-system-media-key_files += "capi-system-media-key.manifest"

capi-system-media-key-devel_files = ""
capi-system-media-key-devel_files += "capi-system-media-key.manifest"
capi-system-media-key-devel_files += "/usr/include/system/media_key.h"
capi-system-media-key-devel_files += "/usr/lib/pkgconfig/*.pc"
capi-system-media-key-devel_files += "/usr/lib/libcapi-system-media-key.so"

FILES_${PN} = "${capi-system-media-key_files}"
FILES_${PN}-devel = "${capi-system-media-key-devel_files}"

PKG_capi-system-media-key= "capi-system-media-key"
PKG_capi-system-media-key-devel= "capi-system-media-key-devel"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require media-key-rdepends.inc
require media-key-depends.inc
require media-key-extraconf.inc
