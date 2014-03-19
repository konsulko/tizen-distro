DESCRIPTION = "XPM format pixmap library"
HOMEPAGE = "http://www.x.org"
SECTION = "Graphics/X Window System"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libXpm"
PACKAGES += "libXpm-devel"

libXpm_files = ""
libXpm_files += "libXpm.manifest"
libXpm_files += "/usr/lib/libXpm.so.4"
libXpm_files += "/usr/lib/libXpm.so.4.11.0"

libXpm-devel_files = ""
libXpm-devel_files += "libXpm.manifest"
libXpm-devel_files += "/usr/bin/cxpm"
libXpm-devel_files += "/usr/bin/sxpm"
libXpm-devel_files += "/usr/include/X11/xpm.h"
libXpm-devel_files += "/usr/lib/libXpm.so"
libXpm-devel_files += "/usr/lib/pkgconfig/xpm.pc"

FILES_${PN} = "${libXpm_files}"
FILES_${PN}-devel = "${libXpm-devel_files}"

PKG_libXpm= "libXpm"
PKG_libXpm-devel= "libXpm-devel"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require libXpm-rdepends.inc
require libXpm-depends.inc
require libXpm-extraconf.inc
