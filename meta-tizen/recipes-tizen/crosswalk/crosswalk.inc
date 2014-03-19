DESCRIPTION = "Crosswalk is an app runtime based on Chromium"
HOMEPAGE = "https://github.com/otcshare/crosswalk"
SECTION = "Web Framework/Web Run Time"
LICENSE = "BSD-3-Clause"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "crosswalk-emulator-support"
PACKAGES += "crosswalk"

crosswalk-emulator-support_files = ""
crosswalk-emulator-support_files += "/usr/lib/xwalk/libosmesa.so"

crosswalk_files = ""
crosswalk_files += "crosswalk.manifest"
crosswalk_files += "/usr/bin/xwalk"
crosswalk_files += "/usr/bin/xwalkctl"
crosswalk_files += "/usr/bin/xwalk-launcher"
crosswalk_files += "/usr/bin/xwalk-pkg-helper"
crosswalk_files += "/usr/lib/xwalk/libffmpegsumo.so"
crosswalk_files += "/usr/lib/xwalk/xwalk"
crosswalk_files += "/usr/lib/xwalk/xwalk.pak"
crosswalk_files += "/usr/share/packages/crosswalk.xml"
crosswalk_files += "/usr/share/icons/default/small/crosswalk.png"
crosswalk_files += "/usr/share/dbus-1/services/org.crosswalkproject.Runtime1.service"
crosswalk_files += "/usr/lib/systemd/user/xwalk.service"

FILES_${PN}-emulator-support = "${crosswalk-emulator-support_files}"
FILES_${PN} = "${crosswalk_files}"

PKG_crosswalk-emulator-support= "crosswalk-emulator-support"
PKG_crosswalk= "crosswalk"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require crosswalk-rdepends.inc
require crosswalk-depends.inc
require crosswalk-extraconf.inc
