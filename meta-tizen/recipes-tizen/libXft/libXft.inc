DESCRIPTION = "X FreeType library"
HOMEPAGE = "http://xorg.freedesktop.org/"
SECTION = "Graphics/X Window System"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libXft-devel"
PACKAGES += "libXft"

libXft-devel_files = ""
libXft-devel_files += "libXft.manifest"
libXft-devel_files += "/usr/include/X11/Xft"
libXft-devel_files += "/usr/lib/libXft.so"
libXft-devel_files += "/usr/lib/pkgconfig/xft.pc"
libXft-devel_files += "/usr/share/man/man3/*"

libXft_files = ""
libXft_files += "libXft.manifest"
libXft_files += "/usr/lib/libXft.so.2*"

FILES_${PN}-devel = "${libXft-devel_files}"
FILES_${PN} = "${libXft_files}"

PKG_libXft-devel= "libXft-devel"
PKG_libXft= "libXft"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require libXft-rdepends.inc
require libXft-depends.inc
require libXft-extraconf.inc
