DESCRIPTION = "tickernoti system popup application"
HOMEPAGE = "http://nohomepage.org"
SECTION = "TO_BE/FILLED_IN"
LICENSE = "APLv2"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "org.tizen.tickernoti-syspopup"

org.tizen.tickernoti-syspopup_files = ""
org.tizen.tickernoti-syspopup_files += "org.tizen.tickernoti-syspopup.manifest"
org.tizen.tickernoti-syspopup_files += "/opt/share/packages/org.tizen.tickernoti-syspopup.xml"
org.tizen.tickernoti-syspopup_files += "/opt/apps/org.tizen.tickernoti-syspopup/res/edje/tickernoti.edj"
org.tizen.tickernoti-syspopup_files += "/opt/apps/org.tizen.tickernoti-syspopup/bin/tickernoti-syspopup"
org.tizen.tickernoti-syspopup_files += "/usr/share/license/org.tizen.tickernoti-syspopup"
org.tizen.tickernoti-syspopup_files += "org.tizen.tickernoti-syspopup.manifest"

FILES_${PN} = "${org.tizen.tickernoti-syspopup_files}"

PKG_org.tizen.tickernoti-syspopup= "org.tizen.tickernoti-syspopup"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require tickernoti-rdepends.inc
require tickernoti-depends.inc
require tickernoti-extraconf.inc
