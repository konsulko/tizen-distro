DESCRIPTION = "Installer for tizen Webruntime"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Web Framework/Utilities"
LICENSE = "Apache-2.0"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "wrt-installer-preinstall-service"
PACKAGES += "wrt-installer"

wrt-installer-preinstall-service_files = ""
wrt-installer-preinstall-service_files += "/lib/systemd/system/wrt-preinstall-widgets.service"
wrt-installer-preinstall-service_files += "/lib/systemd/system/graphical.target.wants/wrt-preinstall-widgets.service"

wrt-installer_files = ""
wrt-installer_files += "wrt-installer.manifest"
wrt-installer_files += "/etc/package-manager/backendlib/libwgt.so"
wrt-installer_files += "/usr/share/license/wrt-installer"

FILES_${PN}-preinstall-service = "${wrt-installer-preinstall-service_files}"
FILES_${PN} = "${wrt-installer_files}"

PKG_wrt-installer-preinstall-service= "wrt-installer-preinstall-service"
PKG_wrt-installer= "wrt-installer"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require wrt-installer-rdepends.inc
require wrt-installer-depends.inc
require wrt-installer-extraconf.inc
