DESCRIPTION = "An utility library of the menu screen"
HOMEPAGE = "http://nohomepage.org"
SECTION = "TO_BE/FILLED_IN"
LICENSE = "Flora Software License"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "org.tizen.menu-screen"

org.tizen.menu-screen_files = ""
org.tizen.menu-screen_files += "org.tizen.menu-screen.manifest"
org.tizen.menu-screen_files += "/usr/apps/org.tizen.menu-screen/bin/menu-screen"
org.tizen.menu-screen_files += "/usr/apps/org.tizen.menu-screen/res/edje/all_apps_portrait.edj"
org.tizen.menu-screen_files += "/usr/apps/org.tizen.menu-screen/res/edje/button_edit.edj"
org.tizen.menu-screen_files += "/usr/apps/org.tizen.menu-screen/res/edje/group_4x4_portrait.edj"
org.tizen.menu-screen_files += "/usr/apps/org.tizen.menu-screen/res/edje/item_4x4.edj"
org.tizen.menu-screen_files += "/usr/apps/org.tizen.menu-screen/res/edje/layout_portrait.edj"
org.tizen.menu-screen_files += "/usr/apps/org.tizen.menu-screen/res/edje/index.edj"
org.tizen.menu-screen_files += "/usr/apps/org.tizen.menu-screen/res/images/default.png"
org.tizen.menu-screen_files += "/usr/apps/org.tizen.menu-screen/res/locale/*/*/*.mo"
org.tizen.menu-screen_files += "/usr/share/packages/org.tizen.menu-screen.xml"
org.tizen.menu-screen_files += "/usr/share/license/org.tizen.menu-screen"
org.tizen.menu-screen_files += "/opt/etc/smack/accesses.d/org.tizen.menu-screen.rule"

FILES_${PN} = "${org.tizen.menu-screen_files}"

PKG_org.tizen.menu-screen= "org.tizen.menu-screen"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require menu-screen-rdepends.inc
require menu-screen-depends.inc
require menu-screen-extraconf.inc
