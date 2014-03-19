DESCRIPTION = "bluetooth system-popup application (bluetooth system popup)"
HOMEPAGE = "http://nohomepage.org"
SECTION = "main"
LICENSE = "Flora Software License"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "org.tizen.bt-syspopup"

org.tizen.bt-syspopup_files = ""
org.tizen.bt-syspopup_files += "org.tizen.bt-syspopup.manifest"
org.tizen.bt-syspopup_files += "/opt/etc/smack/accesses.d/org.tizen.bt-syspopup.rule"
org.tizen.bt-syspopup_files += "/usr/share/packages/org.tizen.bt-syspopup.xml"
org.tizen.bt-syspopup_files += "/opt/apps/org.tizen.bt-syspopup/bin/bt-syspopup"
org.tizen.bt-syspopup_files += "/opt/apps/org.tizen.bt-syspopup/res/edje/*.edj"
org.tizen.bt-syspopup_files += "/opt/share/icons/default/small/org.tizen.bt-syspopup.png"

FILES_${PN} = "${org.tizen.bt-syspopup_files}"

PKG_org.tizen.bt-syspopup= "org.tizen.bt-syspopup"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require bt-syspopup-rdepends.inc
require bt-syspopup-depends.inc
require bt-syspopup-extraconf.inc
