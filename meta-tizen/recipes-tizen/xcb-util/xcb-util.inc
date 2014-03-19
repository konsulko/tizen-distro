DESCRIPTION = "Utility libraries for X C Binding"
HOMEPAGE = "http://xcb.freedesktop.org/"
SECTION = "Graphics/X Window System"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libxcb-util"
PACKAGES += "xcb-util-devel"

libxcb-util_files = ""
libxcb-util_files += "xcb-util.manifest"
libxcb-util_files += "/usr/lib/libxcb-util.so.*"

xcb-util-devel_files = ""
xcb-util-devel_files += "xcb-util.manifest"
xcb-util-devel_files += "/usr/lib/pkgconfig/*.pc"
xcb-util-devel_files += "/usr/lib/*.so"
xcb-util-devel_files += "/usr/include/xcb/*.h"

FILES_lib${PN} = "${libxcb-util_files}"
FILES_${PN}-devel = "${xcb-util-devel_files}"

PKG_libxcb-util= "libxcb-util"
PKG_xcb-util-devel= "xcb-util-devel"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require xcb-util-rdepends.inc
require xcb-util-depends.inc
require xcb-util-extraconf.inc
