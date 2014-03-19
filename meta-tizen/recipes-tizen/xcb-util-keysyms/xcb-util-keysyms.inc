DESCRIPTION = "XCB utility module for X keycode constants and conversions"
HOMEPAGE = "http://xcb.freedesktop.org/"
SECTION = "Development/Libraries/C and C++"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libxcb-keysyms"
PACKAGES += "xcb-util-keysyms-devel"

libxcb-keysyms_files = ""
libxcb-keysyms_files += "xcb-util-keysyms.manifest"
libxcb-keysyms_files += "/usr/lib/libxcb-keysyms.so.1*"

xcb-util-keysyms-devel_files = ""
xcb-util-keysyms-devel_files += "xcb-util-keysyms.manifest"
xcb-util-keysyms-devel_files += "/usr/include/xcb"
xcb-util-keysyms-devel_files += "/usr/lib/libxcb-keysyms.so"
xcb-util-keysyms-devel_files += "/usr/lib/pkgconfig/xcb-keysyms.pc"

FILES_libxcb-keysyms = "${libxcb-keysyms_files}"
FILES_${PN}-devel = "${xcb-util-keysyms-devel_files}"

PKG_libxcb-keysyms= "libxcb-keysyms"
PKG_xcb-util-keysyms-devel= "xcb-util-keysyms-devel"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require xcb-util-keysyms-rdepends.inc
require xcb-util-keysyms-depends.inc
require xcb-util-keysyms-extraconf.inc
