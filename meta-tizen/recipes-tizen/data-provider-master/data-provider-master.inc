DESCRIPTION = "Master service provider for liveboxes"
HOMEPAGE = "http://nohomepage.org"
SECTION = "HomeTF/Livebox"
LICENSE = "Flora License"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "data-provider-master"

data-provider-master_files = ""
data-provider-master_files += "data-provider-master.manifest"
data-provider-master_files += "/etc/rc.d/init.d/data-provider-master"
data-provider-master_files += "/etc/rc.d/rc3.d/S99data-provider-master"
data-provider-master_files += "/usr/bin/data-provider-master"
data-provider-master_files += "/usr/bin/liveinfo"
data-provider-master_files += "/usr/etc/package-manager/parserlib/*"
data-provider-master_files += "/usr/share/data-provider-master/*"
data-provider-master_files += "/lib/systemd/user/data-provider-master.service"
data-provider-master_files += "/lib/systemd/user/data-provider-master.socket"
data-provider-master_files += "/lib/systemd/user/tizen-middleware.target.wants/data-provider-master.service"
data-provider-master_files += "/lib/systemd/user/sockets.target.wants/data-provider-master.socket"
data-provider-master_files += "/usr/share/license/*"
data-provider-master_files += "/opt/usr/share/live_magazine"
data-provider-master_files += "/opt/usr/share/live_magazine/log"
data-provider-master_files += "/opt/usr/share/live_magazine/reader"
data-provider-master_files += "/opt/usr/share/live_magazine/always"
data-provider-master_files += "/opt/dbspace/.livebox.db"
data-provider-master_files += "/opt/dbspace/.livebox.db-journal"

FILES_${PN} = "${data-provider-master_files}"

PKG_data-provider-master= "data-provider-master"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require data-provider-master-rdepends.inc
require data-provider-master-depends.inc
require data-provider-master-extraconf.inc
