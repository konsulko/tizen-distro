DESCRIPTION = "X.Org xkbfile library"
HOMEPAGE = "http://www.x.org"
SECTION = "Graphics/X Window System"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libxkbfile"
PACKAGES += "libxkbfile-devel"

libxkbfile_files = ""
libxkbfile_files += "libxkbfile.manifest"
libxkbfile_files += "/usr/lib/libxkbfile.so.1"
libxkbfile_files += "/usr/lib/libxkbfile.so.1.0.2"

libxkbfile-devel_files = ""
libxkbfile-devel_files += "libxkbfile.manifest"
libxkbfile-devel_files += "/usr/include/X11/extensions/XKBbells.h"
libxkbfile-devel_files += "/usr/include/X11/extensions/XKBconfig.h"
libxkbfile-devel_files += "/usr/include/X11/extensions/XKBfile.h"
libxkbfile-devel_files += "/usr/include/X11/extensions/XKBrules.h"
libxkbfile-devel_files += "/usr/include/X11/extensions/XKM.h"
libxkbfile-devel_files += "/usr/include/X11/extensions/XKMformat.h"
libxkbfile-devel_files += "/usr/lib/libxkbfile.so"
libxkbfile-devel_files += "/usr/lib/pkgconfig/xkbfile.pc"

FILES_${PN} = "${libxkbfile_files}"
FILES_${PN}-devel = "${libxkbfile-devel_files}"

PKG_libxkbfile= "libxkbfile"
PKG_libxkbfile-devel= "libxkbfile-devel"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require libxkbfile-rdepends.inc
require libxkbfile-depends.inc
require libxkbfile-extraconf.inc
