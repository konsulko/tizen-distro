DESCRIPTION = "HP's Printing, Scanning, and Faxing Software"
HOMEPAGE = "http://hplipopensource.com"
SECTION = "Hardware/Printing"
LICENSE = "BSD-3-Clause  GPL-2.0+  MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "hplip"

hplip_files = ""
hplip_files += "hplip.manifest"
hplip_files += "/usr/share/license/hplip"
hplip_files += "/usr/lib/cups/filter"
hplip_files += "/usr/lib/cups/filter/hpcups"

FILES_${PN} = "${hplip_files}"

PKG_hplip= "hplip"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require hplip-rdepends.inc
require hplip-depends.inc
require hplip-extraconf.inc
