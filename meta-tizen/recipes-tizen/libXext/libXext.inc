DESCRIPTION = "Common X Extensions library"
HOMEPAGE = "http://www.x.org"
SECTION = "Graphics/X Window System"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libXext"
PACKAGES += "libXext-devel"

libXext_files = ""
libXext_files += "libXext.manifest"
libXext_files += "COPYING"
libXext_files += "/usr/lib/libXext.so.6"
libXext_files += "/usr/lib/libXext.so.6.4.0"

libXext-devel_files = ""
libXext-devel_files += "libXext.manifest"
libXext-devel_files += "/usr/include/X11/extensions/MITMisc.h"
libXext-devel_files += "/usr/include/X11/extensions/XEVI.h"
libXext-devel_files += "/usr/include/X11/extensions/XLbx.h"
libXext-devel_files += "/usr/include/X11/extensions/XShm.h"
libXext-devel_files += "/usr/include/X11/extensions/Xag.h"
libXext-devel_files += "/usr/include/X11/extensions/Xcup.h"
libXext-devel_files += "/usr/include/X11/extensions/Xdbe.h"
libXext-devel_files += "/usr/include/X11/extensions/Xext.h"
libXext-devel_files += "/usr/include/X11/extensions/Xge.h"
libXext-devel_files += "/usr/include/X11/extensions/dpms.h"
libXext-devel_files += "/usr/include/X11/extensions/extutil.h"
libXext-devel_files += "/usr/include/X11/extensions/multibuf.h"
libXext-devel_files += "/usr/include/X11/extensions/security.h"
libXext-devel_files += "/usr/include/X11/extensions/shape.h"
libXext-devel_files += "/usr/include/X11/extensions/sync.h"
libXext-devel_files += "/usr/include/X11/extensions/xtestext1.h"
libXext-devel_files += "/usr/lib/libXext.so"
libXext-devel_files += "/usr/lib/pkgconfig/xext.pc"

FILES_${PN} = "${libXext_files}"
FILES_${PN}-devel = "${libXext-devel_files}"

PKG_libXext= "libXext"
PKG_libXext-devel= "libXext-devel"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require libXext-rdepends.inc
require libXext-depends.inc
require libXext-extraconf.inc
