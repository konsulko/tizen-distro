DESCRIPTION = "EFL user interface for ConnMan"
HOMEPAGE = "http://svn.enlightenment.org/svn/e/trunk/econnman/"
SECTION = "EFL"
LICENSE = "GPL-2.0"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "econnman"

econnman_files = ""
econnman_files += "econnman.manifest"
econnman_files += "/usr/bin/econnman-bin"
econnman_files += "/usr/share/applications/econnman-agent.desktop"
econnman_files += "/usr/share/applications/econnman.desktop"
econnman_files += "/usr/share/econnman/theme/default.edj"

FILES_${PN} = "${econnman_files}"

PKG_econnman= "econnman"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require econnman-rdepends.inc
require econnman-depends.inc
require econnman-extraconf.inc
