DESCRIPTION = "NFC Core API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Network & Connectivity/NFC"
LICENSE = "Apache-2.0"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "capi-network-nfc"
PACKAGES += "capi-network-nfc-devel"

capi-network-nfc_files = ""
capi-network-nfc_files += "capi-network-nfc.manifest"
capi-network-nfc_files += "/usr/lib/libcapi-network-nfc.so.*"

capi-network-nfc-devel_files = ""
capi-network-nfc-devel_files += "capi-network-nfc.manifest"
capi-network-nfc-devel_files += "/usr/include/network/*.h"
capi-network-nfc-devel_files += "/usr/lib/pkgconfig/*.pc"
capi-network-nfc-devel_files += "/usr/lib/libcapi-network-nfc.so"

FILES_${PN} = "${capi-network-nfc_files}"
FILES_${PN}-devel = "${capi-network-nfc-devel_files}"

PKG_capi-network-nfc= "capi-network-nfc"
PKG_capi-network-nfc-devel= "capi-network-nfc-devel"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require nfc-rdepends.inc
require nfc-depends.inc
require nfc-extraconf.inc
