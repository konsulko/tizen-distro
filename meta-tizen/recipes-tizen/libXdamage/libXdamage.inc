DESCRIPTION = "X Damage extension library"
HOMEPAGE = "http://www.x.org"
SECTION = "Graphics/X Window System"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libXdamage"
PACKAGES += "libXdamage-devel"

libXdamage_files = ""
libXdamage_files += "libXdamage.manifest"
libXdamage_files += "/usr/lib/libXdamage.so.1"
libXdamage_files += "/usr/lib/libXdamage.so.1.1.0"

libXdamage-devel_files = ""
libXdamage-devel_files += "libXdamage.manifest"
libXdamage-devel_files += "/usr/include/X11/extensions/Xdamage.h"
libXdamage-devel_files += "/usr/lib/libXdamage.so"
libXdamage-devel_files += "/usr/lib/pkgconfig/xdamage.pc"

FILES_${PN} = "${libXdamage_files}"
FILES_${PN}-devel = "${libXdamage-devel_files}"

PKG_libXdamage= "libXdamage"
PKG_libXdamage-devel= "libXdamage-devel"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require libXdamage-rdepends.inc
require libXdamage-depends.inc
require libXdamage-extraconf.inc
