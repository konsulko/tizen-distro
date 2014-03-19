DESCRIPTION = "NFC framework manager"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Network & Connectivity/NFC"
LICENSE = "Flora"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "nfc-client-lib"
PACKAGES += "nfc-manager"
PACKAGES += "nfc-client-lib-devel"
PACKAGES += "nfc-common-devel"

nfc-client-lib_files = ""
nfc-client-lib_files += "nfc-manager.manifest"
nfc-client-lib_files += "/usr/lib/libnfc.so.*"

nfc-manager_files = ""
nfc-manager_files += "nfc-manager.manifest"
nfc-manager_files += "/usr/bin/nfc-manager-daemon"
nfc-manager_files += "/usr/lib/systemd/system/nfc-manager.service"
nfc-manager_files += "/usr/lib/systemd/system/multi-user.target.wants/nfc-manager.service"
nfc-manager_files += "/usr/share/dbus-1/system-services/org.tizen.NetNfcService.service"
nfc-manager_files += "/usr/share/packages/nfc-manager.xml"
nfc-manager_files += "/usr/share/nfc-manager-daemon/sounds/*"

nfc-client-lib-devel_files = ""
nfc-client-lib-devel_files += "/usr/lib/libnfc.so"
nfc-client-lib-devel_files += "/usr/lib/pkgconfig/nfc.pc"
nfc-client-lib-devel_files += "/usr/include/nfc/*.h"

nfc-common-devel_files = ""
nfc-common-devel_files += "/usr/lib/pkgconfig/nfc-common.pc"
nfc-common-devel_files += "/usr/include/nfc-common/*.h"

FILES_nfc-client-lib = "${nfc-client-lib_files}"
FILES_${PN} = "${nfc-manager_files}"
FILES_nfc-client-lib-devel = "${nfc-client-lib-devel_files}"
FILES_nfc-common-devel = "${nfc-common-devel_files}"

PKG_nfc-client-lib= "nfc-client-lib"
PKG_nfc-manager= "nfc-manager"
PKG_nfc-client-lib-devel= "nfc-client-lib-devel"
PKG_nfc-common-devel= "nfc-common-devel"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require nfc-manager-rdepends.inc
require nfc-manager-depends.inc
require nfc-manager-extraconf.inc
