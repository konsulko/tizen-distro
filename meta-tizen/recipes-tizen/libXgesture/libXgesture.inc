DESCRIPTION = "X11 Gesture Extension library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libXgesture-devel"
PACKAGES += "libXgesture"

libXgesture-devel_files = ""
libXgesture-devel_files += "libXgesture.manifest"
libXgesture-devel_files += "/usr/include/X11/extensions/*"
libXgesture-devel_files += "/usr/lib/libXgesture.so"
libXgesture-devel_files += "/usr/lib/pkgconfig/xgesture.pc"

libXgesture_files = ""
libXgesture_files += "libXgesture.manifest"
libXgesture_files += "/usr/lib/libXgesture.so.*"

FILES_${PN}-devel = "${libXgesture-devel_files}"
FILES_${PN} = "${libXgesture_files}"

PKG_libXgesture-devel= "libXgesture-devel"
PKG_libXgesture= "libXgesture"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require libXgesture-rdepends.inc
require libXgesture-depends.inc
require libXgesture-extraconf.inc
