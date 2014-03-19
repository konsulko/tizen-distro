DESCRIPTION = "Native rpm installer"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "rpm-installer"

rpm-installer_files = ""
rpm-installer_files += "rpm-installer.manifest"

FILES_${PN} = "${rpm-installer_files}"

PKG_rpm-installer= "rpm-installer"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require rpm-installer-rdepends.inc
require rpm-installer-depends.inc
require rpm-installer-extraconf.inc
