DESCRIPTION = "Create kickstart files for Tizen images"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Base"
LICENSE = "GPL-2.0"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "image-configurations"

image-configurations_files = ""
image-configurations_files += "image-configurations.manifest"
image-configurations_files += "/usr/share/image-configurations/*.ks"
image-configurations_files += "/usr/share/image-configurations/image-configs.xml"

FILES_${PN} = "${image-configurations_files}"

PKG_image-configurations= "image-configurations"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require image-configurations-rdepends.inc
require image-configurations-depends.inc
require image-configurations-extraconf.inc
