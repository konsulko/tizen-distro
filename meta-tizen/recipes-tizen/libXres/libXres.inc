DESCRIPTION = "X-Resource extension client library"
HOMEPAGE = "http://www.x.org"
SECTION = "Graphics/X Window System"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libXres-devel"
PACKAGES += "libXres"

libXres-devel_files = ""
libXres-devel_files += "libXres.manifest"
libXres-devel_files += "/usr/include/X11/extensions/XRes.h"
libXres-devel_files += "/usr/lib/libXRes.so"
libXres-devel_files += "/usr/lib/pkgconfig/xres.pc"

libXres_files = ""
libXres_files += "libXres.manifest"
libXres_files += "/usr/lib/libXRes.so.1"
libXres_files += "/usr/lib/libXRes.so.1.0.0"

FILES_${PN}-devel = "${libXres-devel_files}"
FILES_${PN} = "${libXres_files}"

PKG_libXres-devel= "libXres-devel"
PKG_libXres= "libXres"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require libXres-rdepends.inc
require libXres-depends.inc
require libXres-extraconf.inc
