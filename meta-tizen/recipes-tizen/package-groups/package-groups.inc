DESCRIPTION = "Tizen Package Groups"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Base"
LICENSE = "GPL-2.0"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "package-groups"

package-groups_files = ""
package-groups_files += "package-groups.manifest"
package-groups_files += "/usr/share/package-groups/*.xml"

FILES_${PN} = "${package-groups_files}"

PKG_package-groups= "package-groups"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require package-groups-rdepends.inc
require package-groups-depends.inc
require package-groups-extraconf.inc
