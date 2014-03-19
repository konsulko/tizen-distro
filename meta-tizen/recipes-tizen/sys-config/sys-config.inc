DESCRIPTION = "Configuration for OSP Framework Foundation library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache-2.0"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "osp-sys-config"
PACKAGES += "osp-sys-config-ref"

osp-sys-config_files = ""
osp-sys-config_files += "osp-sys-config.manifest"
osp-sys-config_files += "/usr/share/license/*"
osp-sys-config_files += "/usr/share/appsvc/*"
osp-sys-config_files += "/usr/etc/*"
osp-sys-config_files += "/usr/etc/tizen-core/*"
osp-sys-config_files += "/usr/etc/.smack"

osp-sys-config-ref_files = ""
osp-sys-config-ref_files += "osp-sys-config.manifest"
osp-sys-config-ref_files += "/usr/etc/tizen-ref/*"

FILES_${PN} = "${osp-sys-config_files}"
FILES_${PN}-ref = "${osp-sys-config-ref_files}"

PKG_osp-sys-config= "osp-sys-config"
PKG_osp-sys-config-ref= "osp-sys-config-ref"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require sys-config-rdepends.inc
require sys-config-depends.inc
require sys-config-extraconf.inc
