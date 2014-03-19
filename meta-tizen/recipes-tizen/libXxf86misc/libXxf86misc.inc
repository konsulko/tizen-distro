DESCRIPTION = "X11 XFree86 miscellaneous extension library"
HOMEPAGE = "http://www.x.org/"
SECTION = "System/Libraries"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libXxf86misc-devel"
PACKAGES += "libXxf86misc"

libXxf86misc-devel_files = ""
libXxf86misc-devel_files += "libXxf86misc.manifest"
libXxf86misc-devel_files += "/usr/lib/libXxf86misc.so"
libXxf86misc-devel_files += "/usr/lib/pkgconfig/xxf86misc.pc"
libXxf86misc-devel_files += "/usr/share/man/man3/*.3*"

libXxf86misc_files = ""
libXxf86misc_files += "libXxf86misc.manifest"
libXxf86misc_files += "/usr/lib/libXxf86misc.so.1"
libXxf86misc_files += "/usr/lib/libXxf86misc.so.1.1.0"

FILES_${PN}-devel = "${libXxf86misc-devel_files}"
FILES_${PN} = "${libXxf86misc_files}"

PKG_libXxf86misc-devel= "libXxf86misc-devel"
PKG_libXxf86misc= "libXxf86misc"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require libXxf86misc-rdepends.inc
require libXxf86misc-depends.inc
require libXxf86misc-extraconf.inc
