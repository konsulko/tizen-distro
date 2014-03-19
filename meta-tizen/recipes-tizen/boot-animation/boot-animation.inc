DESCRIPTION = "Boot animation"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Samsung/Application"
LICENSE = "Flora Software License"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "boot-animation-docs"
PACKAGES += "boot-animation"

boot-animation-docs_files = ""
boot-animation-docs_files += "/usr/share/info"
boot-animation-docs_files += "/usr/share/man"

boot-animation_files = ""
boot-animation_files += "boot-animation.manifest"
boot-animation_files += "/etc/init.d/boot-ani"
boot-animation_files += "/usr/share/edje/poweroff.edj"
boot-animation_files += "/usr/share/edje/poweron.edj"
boot-animation_files += "/usr/bin/boot-animation"
boot-animation_files += "/usr/lib/systemd/user/boot-animation.service"
boot-animation_files += "/usr/lib/systemd/user/core-efl.target.wants/boot-animation.service"
boot-animation_files += "/usr/share/license/boot-animation"

FILES_${PN}-docs = "${boot-animation-docs_files}"
FILES_${PN} = "${boot-animation_files}"

PKG_boot-animation-docs= "boot-animation-docs"
PKG_boot-animation= "boot-animation"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require boot-animation-rdepends.inc
require boot-animation-depends.inc
require boot-animation-extraconf.inc
