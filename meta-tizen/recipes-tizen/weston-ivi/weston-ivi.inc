DESCRIPTION = "Tizen IVI Weston configuration and set-up"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Automotive/Configuration"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "weston-ivi-config"
PACKAGES += "weston-ivi"

weston-ivi-config_files = ""
weston-ivi-config_files += "weston-ivi.manifest"
weston-ivi-config_files += "/etc/xdg/weston/weston.ini"

weston-ivi_files = ""
weston-ivi_files += "weston-ivi.manifest"
weston-ivi_files += "/lib/systemd/user/weston.service"
weston-ivi_files += "/lib/systemd/user/weston.target.wants/weston.service"
weston-ivi_files += "/etc/profile.d/*"

FILES_${PN}-config = "${weston-ivi-config_files}"
FILES_${PN} = "${weston-ivi_files}"

PKG_weston-ivi-config= "weston-ivi-config"
PKG_weston-ivi= "weston-ivi"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require weston-ivi-rdepends.inc
require weston-ivi-depends.inc
require weston-ivi-extraconf.inc
