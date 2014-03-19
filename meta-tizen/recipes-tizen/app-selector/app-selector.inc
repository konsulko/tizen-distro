DESCRIPTION = "Application selector"
HOMEPAGE = "http://nohomepage.org"
SECTION = "TO_BE/FILLED_IN"
LICENSE = "Flora Software License"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "org.tizen.app-selector"

org.tizen.app-selector_files = ""
org.tizen.app-selector_files += "org.tizen.app-selector.manifest"
org.tizen.app-selector_files += "/usr/bin/app-selector"
org.tizen.app-selector_files += "/usr/share/edje/app-selector/app-selector.edj"
org.tizen.app-selector_files += "/usr/share/packages/org.tizen.app-selector.xml"
org.tizen.app-selector_files += "/usr/share/locale/*/LC_MESSAGES/*.mo"
org.tizen.app-selector_files += "/opt/etc/smack/accesses.d/org.tizen.app-selector.rule"

FILES_${PN} = "${org.tizen.app-selector_files}"

PKG_org.tizen.app-selector= "org.tizen.app-selector"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require app-selector-rdepends.inc
require app-selector-depends.inc
require app-selector-extraconf.inc
