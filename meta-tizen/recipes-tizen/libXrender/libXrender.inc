DESCRIPTION = "X Rendering Extension library"
HOMEPAGE = "http://cgit.freedesktop.org/xorg/lib/libXrender/"
SECTION = "Graphics/X Window System"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libXrender-devel"
PACKAGES += "libXrender"

libXrender-devel_files = ""
libXrender-devel_files += "libXrender.manifest"
libXrender-devel_files += "/usr/include/X11/*"
libXrender-devel_files += "/usr/lib/libXrender.so"
libXrender-devel_files += "/usr/lib/pkgconfig/xrender.pc"
libXrender-devel_files += "/usr/share/doc/packages/libXrender"

libXrender_files = ""
libXrender_files += "libXrender.manifest"
libXrender_files += "/usr/lib/libXrender.so.1*"

FILES_${PN}-devel = "${libXrender-devel_files}"
FILES_${PN} = "${libXrender_files}"

PKG_libXrender-devel= "libXrender-devel"
PKG_libXrender= "libXrender"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require libXrender-rdepends.inc
require libXrender-depends.inc
require libXrender-extraconf.inc
