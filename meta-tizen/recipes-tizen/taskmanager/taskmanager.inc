DESCRIPTION = "Task Manager"
HOMEPAGE = "http://nohomepage.org"
SECTION = "devel"
LICENSE = "Flora Software License"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "org.tizen.taskmgr"

org.tizen.taskmgr_files = ""
org.tizen.taskmgr_files += "org.tizen.taskmgr.manifest"
org.tizen.taskmgr_files += "/usr/apps/org.tizen.taskmgr/bin/*"
org.tizen.taskmgr_files += "/usr/apps/org.tizen.taskmgr/res/*"
org.tizen.taskmgr_files += "/opt/usr/apps/org.tizen.taskmgr/data"
org.tizen.taskmgr_files += "/usr/share/packages/*"
org.tizen.taskmgr_files += "/usr/share/icons/default/small/org.tizen.taskmgr.png"
org.tizen.taskmgr_files += "/opt/etc/smack/accesses.d/org.tizen.taskmgr.rule"

FILES_${PN} = "${org.tizen.taskmgr_files}"

PKG_org.tizen.taskmgr= "org.tizen.taskmgr"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require taskmanager-rdepends.inc
require taskmanager-depends.inc
require taskmanager-extraconf.inc
