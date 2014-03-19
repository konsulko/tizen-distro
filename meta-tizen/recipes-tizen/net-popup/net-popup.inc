DESCRIPTION = "Network Notification Popup application"
HOMEPAGE = "http://nohomepage.org"
SECTION = "App/Network"
LICENSE = "Flora License"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "org.tizen.net-popup"

org.tizen.net-popup_files = ""
org.tizen.net-popup_files += "org.tizen.net-popup.manifest"
org.tizen.net-popup_files += "/usr/apps/org.tizen.net-popup/bin/net-popup"
org.tizen.net-popup_files += "/usr/share/packages/org.tizen.net-popup.xml"
org.tizen.net-popup_files += "/usr/share/license/org.tizen.net-popup"
org.tizen.net-popup_files += "/usr/share/locale/*/LC_MESSAGES/net-popup.mo"
org.tizen.net-popup_files += "/etc/smack/accesses.d/org.tizen.net-popup.rule"

FILES_${PN} = "${org.tizen.net-popup_files}"

PKG_org.tizen.net-popup= "org.tizen.net-popup"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require net-popup-rdepends.inc
require net-popup-depends.inc
require net-popup-extraconf.inc
