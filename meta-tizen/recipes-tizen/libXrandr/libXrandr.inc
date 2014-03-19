DESCRIPTION = "X Resize and Rotate Extension C Library"
HOMEPAGE = "http://www.x.org"
SECTION = "Graphics/X Window System"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libXrandr"
PACKAGES += "libXrandr-devel"

libXrandr_files = ""
libXrandr_files += "libXrandr.manifest"
libXrandr_files += "/usr/lib/libXrandr.so.2"
libXrandr_files += "/usr/lib/libXrandr.so.2.2.0"

libXrandr-devel_files = ""
libXrandr-devel_files += "libXrandr.manifest"
libXrandr-devel_files += "/usr/include/X11/extensions/Xrandr.h"
libXrandr-devel_files += "/usr/lib/libXrandr.so"
libXrandr-devel_files += "/usr/lib/pkgconfig/xrandr.pc"

FILES_${PN} = "${libXrandr_files}"
FILES_${PN}-devel = "${libXrandr-devel_files}"

PKG_libXrandr= "libXrandr"
PKG_libXrandr-devel= "libXrandr-devel"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require libXrandr-rdepends.inc
require libXrandr-depends.inc
require libXrandr-extraconf.inc
