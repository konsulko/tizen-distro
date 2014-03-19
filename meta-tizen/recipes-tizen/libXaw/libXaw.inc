DESCRIPTION = "X Athena Widget Set"
HOMEPAGE = "http://www.x.org"
SECTION = "Graphics/X Window System"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libXaw-devel"
PACKAGES += "libXaw"

libXaw-devel_files = ""
libXaw-devel_files += "libXaw.manifest"
libXaw-devel_files += "/usr/include/X11/Xaw"
libXaw-devel_files += "/usr/include/X11/Xaw/*.h"
libXaw-devel_files += "/usr/include/X11/Xaw/Template.c"
libXaw-devel_files += "/usr/lib/libXaw.so"
libXaw-devel_files += "/usr/lib/libXaw7.so"
libXaw-devel_files += "/usr/lib/pkgconfig/xaw7.pc"

libXaw_files = ""
libXaw_files += "libXaw.manifest"
libXaw_files += "/usr/lib/libXaw.so.7"
libXaw_files += "/usr/lib/libXaw7.so.7"
libXaw_files += "/usr/lib/libXaw7.so.7.0.0"

FILES_${PN}-devel = "${libXaw-devel_files}"
FILES_${PN} = "${libXaw_files}"

PKG_libXaw-devel= "libXaw-devel"
PKG_libXaw= "libXaw"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require libXaw-rdepends.inc
require libXaw-depends.inc
require libXaw-extraconf.inc
