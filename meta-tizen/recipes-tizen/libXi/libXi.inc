DESCRIPTION = "X.org libXi Client library for XInput."
HOMEPAGE = "http://www.x.org"
SECTION = "Graphics/X Window System"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libXi"
PACKAGES += "libXi-devel"

libXi_files = ""
libXi_files += "libXi.manifest"
libXi_files += "/usr/lib/libXi.so.6"
libXi_files += "/usr/lib/libXi.so.6.1.0"

libXi-devel_files = ""
libXi-devel_files += "libXi.manifest"
libXi-devel_files += "/usr/include/X11/extensions/XInput.h"
libXi-devel_files += "/usr/include/X11/extensions/XInput2.h"
libXi-devel_files += "/usr/lib/libXi.so"
libXi-devel_files += "/usr/lib/pkgconfig/xi.pc"

FILES_${PN} = "${libXi_files}"
FILES_${PN}-devel = "${libXi-devel_files}"

PKG_libXi= "libXi"
PKG_libXi-devel= "libXi-devel"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require libXi-rdepends.inc
require libXi-depends.inc
require libXi-extraconf.inc
