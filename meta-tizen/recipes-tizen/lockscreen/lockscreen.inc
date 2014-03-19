DESCRIPTION = "lockscreen application"
HOMEPAGE = "http://nohomepage.org"
SECTION = "TBD"
LICENSE = "Apache"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "org.tizen.lockscreen"

org.tizen.lockscreen_files = ""
org.tizen.lockscreen_files += "org.tizen.lockscreen.manifest"
org.tizen.lockscreen_files += "/usr/apps/org.tizen.lockscreen/*"
org.tizen.lockscreen_files += "/usr/share/packages/org.tizen.lockscreen.xml"
org.tizen.lockscreen_files += "/usr/share/license/org.tizen.lockscreen"
org.tizen.lockscreen_files += "/usr/apps/org.tizen.lockscreen/res/locale/*/LC_MESSAGES/lockscreen.mo"

FILES_${PN} = "${org.tizen.lockscreen_files}"

PKG_org.tizen.lockscreen= "org.tizen.lockscreen"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require lockscreen-rdepends.inc
require lockscreen-depends.inc
require lockscreen-extraconf.inc
