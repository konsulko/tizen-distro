DESCRIPTION = "X-Video Motion Compensation library"
HOMEPAGE = "http://xorg.freedesktop.org/"
SECTION = "System/Libraries"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libXvMC"
PACKAGES += "libXvMC-devel"

libXvMC_files = ""
libXvMC_files += "libXvMC.manifest"
libXvMC_files += "/usr/lib/libXvMC*.so.1*"

libXvMC-devel_files = ""
libXvMC-devel_files += "libXvMC.manifest"
libXvMC-devel_files += "/usr/include/X11/*"
libXvMC-devel_files += "/usr/lib/libXvMC*.so"
libXvMC-devel_files += "/usr/lib/pkgconfig/xvmc.pc"

FILES_${PN} = "${libXvMC_files}"
FILES_${PN}-devel = "${libXvMC-devel_files}"

PKG_libXvMC= "libXvMC"
PKG_libXvMC-devel= "libXvMC-devel"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require libXvMC-rdepends.inc
require libXvMC-depends.inc
require libXvMC-extraconf.inc
