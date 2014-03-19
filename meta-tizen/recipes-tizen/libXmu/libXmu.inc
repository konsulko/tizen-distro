DESCRIPTION = "X.org Xmu library"
HOMEPAGE = "http://www.x.org"
SECTION = "Graphics/X Window System"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libXmu-devel"
PACKAGES += "libXmu"

libXmu-devel_files = ""
libXmu-devel_files += "libXmu.manifest"
libXmu-devel_files += "/usr/include/X11/Xmu"
libXmu-devel_files += "/usr/include/X11/Xmu/Atoms.h"
libXmu-devel_files += "/usr/include/X11/Xmu/CharSet.h"
libXmu-devel_files += "/usr/include/X11/Xmu/CloseHook.h"
libXmu-devel_files += "/usr/include/X11/Xmu/Converters.h"
libXmu-devel_files += "/usr/include/X11/Xmu/CurUtil.h"
libXmu-devel_files += "/usr/include/X11/Xmu/CvtCache.h"
libXmu-devel_files += "/usr/include/X11/Xmu/DisplayQue.h"
libXmu-devel_files += "/usr/include/X11/Xmu/Drawing.h"
libXmu-devel_files += "/usr/include/X11/Xmu/Editres.h"
libXmu-devel_files += "/usr/include/X11/Xmu/EditresP.h"
libXmu-devel_files += "/usr/include/X11/Xmu/Error.h"
libXmu-devel_files += "/usr/include/X11/Xmu/ExtAgent.h"
libXmu-devel_files += "/usr/include/X11/Xmu/Initer.h"
libXmu-devel_files += "/usr/include/X11/Xmu/Lookup.h"
libXmu-devel_files += "/usr/include/X11/Xmu/Misc.h"
libXmu-devel_files += "/usr/include/X11/Xmu/StdCmap.h"
libXmu-devel_files += "/usr/include/X11/Xmu/StdSel.h"
libXmu-devel_files += "/usr/include/X11/Xmu/SysUtil.h"
libXmu-devel_files += "/usr/include/X11/Xmu/WhitePoint.h"
libXmu-devel_files += "/usr/include/X11/Xmu/WidgetNode.h"
libXmu-devel_files += "/usr/include/X11/Xmu/WinUtil.h"
libXmu-devel_files += "/usr/include/X11/Xmu/Xct.h"
libXmu-devel_files += "/usr/include/X11/Xmu/Xmu.h"
libXmu-devel_files += "/usr/lib/libXmu.so"
libXmu-devel_files += "/usr/lib/libXmuu.so"
libXmu-devel_files += "/usr/lib/pkgconfig/xmu.pc"
libXmu-devel_files += "/usr/lib/pkgconfig/xmuu.pc"

libXmu_files = ""
libXmu_files += "libXmu.manifest"
libXmu_files += "/usr/lib/libXmu.so.6"
libXmu_files += "/usr/lib/libXmu.so.6.2.0"
libXmu_files += "/usr/lib/libXmuu.so.1"
libXmu_files += "/usr/lib/libXmuu.so.1.0.0"

FILES_${PN}-devel = "${libXmu-devel_files}"
FILES_${PN} = "${libXmu_files}"

PKG_libXmu-devel= "libXmu-devel"
PKG_libXmu= "libXmu"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require libXmu-rdepends.inc
require libXmu-depends.inc
require libXmu-extraconf.inc
