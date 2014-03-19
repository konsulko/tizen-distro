DESCRIPTION = "camera application"
HOMEPAGE = "http://nohomepage.org"
SECTION = "TO_BE/FILLED_IN"
LICENSE = "Flora Software License"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "org.tizen.camera-app"

org.tizen.camera-app_files = ""
org.tizen.camera-app_files += "org.tizen.camera-app.manifest"
org.tizen.camera-app_files += "/usr/share/icons/default/small/org.tizen.camera-app.png"
org.tizen.camera-app_files += "/usr/share/packages/org.tizen.camera-app.xml"
org.tizen.camera-app_files += "/etc/smack/accesses.d/org.tizen.camera-app.rule"
org.tizen.camera-app_files += "/usr/apps/org.tizen.camera-app/bin/camera"

FILES_${PN} = "${org.tizen.camera-app_files}"

PKG_org.tizen.camera-app= "org.tizen.camera-app"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require camera-rdepends.inc
require camera-depends.inc
require camera-extraconf.inc
