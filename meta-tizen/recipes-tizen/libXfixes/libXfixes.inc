DESCRIPTION = "X Fixes library"
HOMEPAGE = "http://www.x.org"
SECTION = "Graphics/X Window System"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libXfixes"
PACKAGES += "libXfixes-devel"

libXfixes_files = ""
libXfixes_files += "libXfixes.manifest"
libXfixes_files += "/usr/lib/libXfixes.so.3"
libXfixes_files += "/usr/lib/libXfixes.so.3.1.0"

libXfixes-devel_files = ""
libXfixes-devel_files += "libXfixes.manifest"
libXfixes-devel_files += "/usr/include/X11/extensions/Xfixes.h"
libXfixes-devel_files += "/usr/lib/libXfixes.so"
libXfixes-devel_files += "/usr/lib/pkgconfig/xfixes.pc"

FILES_${PN} = "${libXfixes_files}"
FILES_${PN}-devel = "${libXfixes-devel_files}"

PKG_libXfixes= "libXfixes"
PKG_libXfixes-devel= "libXfixes-devel"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require libXfixes-rdepends.inc
require libXfixes-depends.inc
require libXfixes-extraconf.inc
