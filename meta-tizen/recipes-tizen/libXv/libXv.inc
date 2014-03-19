DESCRIPTION = "Xvideo extension library"
HOMEPAGE = "http://www.x.org"
SECTION = "Graphics/X Window System"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libXv-devel"
PACKAGES += "libXv"

libXv-devel_files = ""
libXv-devel_files += "libXv.manifest"
libXv-devel_files += "man/xv-library-v2.2.txt"
libXv-devel_files += "/usr/include/X11/extensions/Xvlib.h"
libXv-devel_files += "/usr/lib/libXv.so"
libXv-devel_files += "/usr/lib/pkgconfig/xv.pc"

libXv_files = ""
libXv_files += "libXv.manifest"
libXv_files += "/usr/lib/libXv.so.1"
libXv_files += "/usr/lib/libXv.so.1.0.0"

FILES_${PN}-devel = "${libXv-devel_files}"
FILES_${PN} = "${libXv_files}"

PKG_libXv-devel= "libXv-devel"
PKG_libXv= "libXv"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require libXv-rdepends.inc
require libXv-depends.inc
require libXv-extraconf.inc
