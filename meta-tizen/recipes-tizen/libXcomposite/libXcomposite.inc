DESCRIPTION = "X Composite Extension library"
HOMEPAGE = "http://www.x.org"
SECTION = "Graphics/X Window System"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libXcomposite"
PACKAGES += "libXcomposite-devel"

libXcomposite_files = ""
libXcomposite_files += "libXcomposite.manifest"
libXcomposite_files += "/usr/lib/libXcomposite.so.1"
libXcomposite_files += "/usr/lib/libXcomposite.so.1.0.0"

libXcomposite-devel_files = ""
libXcomposite-devel_files += "libXcomposite.manifest"
libXcomposite-devel_files += "/usr/include/X11/extensions/Xcomposite.h"
libXcomposite-devel_files += "/usr/lib/libXcomposite.so"
libXcomposite-devel_files += "/usr/lib/pkgconfig/xcomposite.pc"

FILES_${PN} = "${libXcomposite_files}"
FILES_${PN}-devel = "${libXcomposite-devel_files}"

PKG_libXcomposite= "libXcomposite"
PKG_libXcomposite-devel= "libXcomposite-devel"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require libXcomposite-rdepends.inc
require libXcomposite-depends.inc
require libXcomposite-extraconf.inc
