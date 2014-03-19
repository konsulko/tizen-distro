DESCRIPTION = "Freely licensed alternative to the GLUT library"
HOMEPAGE = "http://freeglut.sourceforge.net/"
SECTION = "System/Libraries"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libglut"
PACKAGES += "freeglut-devel"

libglut_files = ""
libglut_files += "freeglut.manifest"
libglut_files += "COPYING"
libglut_files += "/usr/lib/libglut.so.*"

freeglut-devel_files = ""
freeglut-devel_files += "freeglut.manifest"
freeglut-devel_files += "/usr/include/GL"
freeglut-devel_files += "/usr/lib/libglut.so"

FILES_libglut = "${libglut_files}"
FILES_${PN}-devel = "${freeglut-devel_files}"

PKG_libglut= "libglut"
PKG_freeglut-devel= "freeglut-devel"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require freeglut-rdepends.inc
require freeglut-depends.inc
require freeglut-extraconf.inc
