DESCRIPTION = "Xinerama protocol library"
HOMEPAGE = "http://www.x.org"
SECTION = "Graphics/X Window System"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libXinerama"
PACKAGES += "libXinerama-devel"

libXinerama_files = ""
libXinerama_files += "libXinerama.manifest"
libXinerama_files += "/usr/lib/libXinerama.so.1"
libXinerama_files += "/usr/lib/libXinerama.so.1.0.0"

libXinerama-devel_files = ""
libXinerama-devel_files += "libXinerama.manifest"
libXinerama-devel_files += "/usr/lib/libXinerama.so"
libXinerama-devel_files += "/usr/lib/pkgconfig/xinerama.pc"
libXinerama-devel_files += "/usr/include/X11/extensions/Xinerama.h"
libXinerama-devel_files += "/usr/include/X11/extensions/panoramiXext.h"

FILES_${PN} = "${libXinerama_files}"
FILES_${PN}-devel = "${libXinerama-devel_files}"

PKG_libXinerama= "libXinerama"
PKG_libXinerama-devel= "libXinerama-devel"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require libXinerama-rdepends.inc
require libXinerama-depends.inc
require libXinerama-extraconf.inc
