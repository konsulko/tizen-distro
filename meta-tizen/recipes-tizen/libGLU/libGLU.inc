DESCRIPTION = "Graphics Library Utilities (GLU)"
HOMEPAGE = "http://www.mesa3d.org"
SECTION = "Development/Libraries/C and C++"
LICENSE = "SGI Free B"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libGLU-devel"
PACKAGES += "libGLU"

libGLU-devel_files = ""
libGLU-devel_files += "libGLU.manifest"
libGLU-devel_files += "/usr/include/GL"
libGLU-devel_files += "/usr/lib/pkgconfig/glu.pc"
libGLU-devel_files += "/usr/lib/libGLU.so"

libGLU_files = ""
libGLU_files += "libGLU.manifest"
libGLU_files += "/usr/lib/libGLU.so.1*"

FILES_${PN}-devel = "${libGLU-devel_files}"
FILES_${PN} = "${libGLU_files}"

PKG_libGLU-devel= "libGLU-devel"
PKG_libGLU= "libGLU"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require libGLU-rdepends.inc
require libGLU-depends.inc
require libGLU-extraconf.inc
