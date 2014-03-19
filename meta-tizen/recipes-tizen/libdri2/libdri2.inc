DESCRIPTION = "X.Org DRI2 Extension client library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libdri2"
PACKAGES += "libdri2-devel"

libdri2_files = ""
libdri2_files += "libdri2.manifest"
libdri2_files += "/usr/share/license/libdri2"
libdri2_files += "/usr/lib/libdri2.so.*"

libdri2-devel_files = ""
libdri2-devel_files += "libdri2.manifest"
libdri2-devel_files += "/usr/lib/libdri2.so"
libdri2-devel_files += "/usr/include/dri2/*"
libdri2-devel_files += "/usr/lib/pkgconfig/*"

FILES_${PN} = "${libdri2_files}"
FILES_${PN}-devel = "${libdri2-devel_files}"

PKG_libdri2= "libdri2"
PKG_libdri2-devel= "libdri2-devel"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require libdri2-rdepends.inc
require libdri2-depends.inc
require libdri2-extraconf.inc
