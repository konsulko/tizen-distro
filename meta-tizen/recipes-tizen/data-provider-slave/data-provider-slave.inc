DESCRIPTION = "Plugin type livebox service provider."
HOMEPAGE = "http://nohomepage.org"
SECTION = "HomeTF/Livebox"
LICENSE = "Flora License"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "org.tizen.data-provider-slave"

org.tizen.data-provider-slave_files = ""
org.tizen.data-provider-slave_files += "org.tizen.data-provider-slave.manifest"
org.tizen.data-provider-slave_files += "/usr/apps/org.tizen.data-provider-slave"
org.tizen.data-provider-slave_files += "/usr/share/packages/org.tizen.data-provider-slave.xml"
org.tizen.data-provider-slave_files += "/usr/share/license/*"
org.tizen.data-provider-slave_files += "/etc/smack/accesses.d/org.tizen.data-provider-slave.rule"
org.tizen.data-provider-slave_files += "/opt/usr/apps/org.tizen.data-provider-slave/data"

FILES_${PN} = "${org.tizen.data-provider-slave_files}"

PKG_org.tizen.data-provider-slave= "org.tizen.data-provider-slave"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require data-provider-slave-rdepends.inc
require data-provider-slave-depends.inc
require data-provider-slave-extraconf.inc
