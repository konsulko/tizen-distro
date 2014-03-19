DESCRIPTION = "starter"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Base/Startup"
LICENSE = "TO_BE/FILLED_IN"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "starter"

starter_files = ""
starter_files += "starter.manifest"
starter_files += "/etc/init.d/rd4starter"
starter_files += "/etc/init.d/rd3starter"
starter_files += "/usr/bin/starter"
starter_files += "/usr/ug/lib/libug-lockscreen-options.so"
starter_files += "/usr/ug/lib/libug-lockscreen-options.so.0.1.0"
starter_files += "/usr/lib/systemd/user/starter.path"
starter_files += "/usr/lib/systemd/user/starter.service"
starter_files += "/usr/lib/systemd/user/core-efl.target.wants/starter.path"
starter_files += "/usr/share/license/starter"
starter_files += "/opt/data/home-daemon"

FILES_${PN} = "${starter_files}"

PKG_starter= "starter"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require starter-rdepends.inc
require starter-depends.inc
require starter-extraconf.inc
