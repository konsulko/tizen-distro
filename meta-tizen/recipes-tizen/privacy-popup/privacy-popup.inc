DESCRIPTION = "privacy-popup"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Base"
LICENSE = "Apache-2.0 or Flora"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "privacy-popup"

privacy-popup_files = ""
privacy-popup_files += "packaging/tizenprv00.privacy-popup.manifest"
privacy-popup_files += "/usr/bin/tizenprv00.privacy-popup"
privacy-popup_files += "/usr/share/packages/privacy-popup.xml"

FILES_${PN} = "${privacy-popup_files}"

PKG_privacy-popup= "privacy-popup"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require privacy-popup-rdepends.inc
require privacy-popup-depends.inc
require privacy-popup-extraconf.inc
