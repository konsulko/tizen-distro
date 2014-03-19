DESCRIPTION = "Lock screen application"
HOMEPAGE = "http://nohomepage.org"
SECTION = "TBD"
LICENSE = "Flora Software License"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "org.tizen.draglock"

org.tizen.draglock_files = ""
org.tizen.draglock_files += "/opt/apps/org.tizen.draglock/res/locale"
org.tizen.draglock_files += "/opt/apps/org.tizen.draglock/bin/draglock"
org.tizen.draglock_files += "/opt/apps/org.tizen.draglock/res/edje/draglock.edj"
org.tizen.draglock_files += "/opt/share/packages/org.tizen.draglock.xml"

FILES_${PN} = "${org.tizen.draglock_files}"

PKG_org.tizen.draglock= "org.tizen.draglock"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require draglock-rdepends.inc
require draglock-depends.inc
require draglock-extraconf.inc
