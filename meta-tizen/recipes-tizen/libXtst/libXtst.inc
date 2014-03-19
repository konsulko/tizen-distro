DESCRIPTION = "Xlib-based client API for the XTEST and RECORD extensions"
HOMEPAGE = "http://xorg.freedesktop.org/"
SECTION = "Graphics/X Window System"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libXtst"
PACKAGES += "libXtst-devel"

libXtst_files = ""
libXtst_files += "libXtst.manifest"
libXtst_files += "/usr/lib/libXtst.so.6*"

libXtst-devel_files = ""
libXtst-devel_files += "libXtst.manifest"
libXtst-devel_files += "/usr/include/X11/*"
libXtst-devel_files += "/usr/lib/libXtst.so"
libXtst-devel_files += "/usr/lib/pkgconfig/xtst.pc"

FILES_${PN} = "${libXtst_files}"
FILES_${PN}-devel = "${libXtst-devel_files}"

PKG_libXtst= "libXtst"
PKG_libXtst-devel= "libXtst-devel"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require libXtst-rdepends.inc
require libXtst-depends.inc
require libXtst-extraconf.inc
