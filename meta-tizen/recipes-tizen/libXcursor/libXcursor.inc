DESCRIPTION = "Cursor management library"
HOMEPAGE = "http://www.x.org"
SECTION = "Graphics/X Window System"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libXcursor-devel"
PACKAGES += "libXcursor"

libXcursor-devel_files = ""
libXcursor-devel_files += "libXcursor.manifest"
libXcursor-devel_files += "/usr/include/X11/Xcursor"
libXcursor-devel_files += "/usr/include/X11/Xcursor/Xcursor.h"
libXcursor-devel_files += "/usr/lib/libXcursor.so"
libXcursor-devel_files += "/usr/lib/pkgconfig/xcursor.pc"

libXcursor_files = ""
libXcursor_files += "libXcursor.manifest"
libXcursor_files += "/usr/lib/libXcursor.so.1"
libXcursor_files += "/usr/lib/libXcursor.so.1.0.2"
libXcursor_files += "/usr/share/icons/default"

FILES_${PN}-devel = "${libXcursor-devel_files}"
FILES_${PN} = "${libXcursor_files}"

PKG_libXcursor-devel= "libXcursor-devel"
PKG_libXcursor= "libXcursor"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require libXcursor-rdepends.inc
require libXcursor-depends.inc
require libXcursor-extraconf.inc
