DESCRIPTION = "Menu daemon"
HOMEPAGE = "http://nohomepage.org"
SECTION = "apps"
LICENSE = "Flora Software License"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "menu-daemon"

menu-daemon_files = ""
menu-daemon_files += "menu-daemon.manifest"
menu-daemon_files += "/etc/init.d/menudaemon"
menu-daemon_files += "/etc/init.d/menudaemon.fast"
menu-daemon_files += "/usr/bin/menu-daemon"

FILES_${PN} = "${menu-daemon_files}"

PKG_menu-daemon= "menu-daemon"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require menu-daemon-rdepends.inc
require menu-daemon-depends.inc
require menu-daemon-extraconf.inc
