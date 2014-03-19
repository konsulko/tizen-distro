DESCRIPTION = "X Toolkit Intrinsics library"
HOMEPAGE = "http://www.x.org"
SECTION = "Graphics/X Window System"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libXt-devel"
PACKAGES += "libXt"

libXt-devel_files = ""
libXt-devel_files += "libXt.manifest"
libXt-devel_files += "/usr/include/X11/CallbackI.h"
libXt-devel_files += "/usr/include/X11/Composite.h"
libXt-devel_files += "/usr/include/X11/CompositeP.h"
libXt-devel_files += "/usr/include/X11/ConstrainP.h"
libXt-devel_files += "/usr/include/X11/Constraint.h"
libXt-devel_files += "/usr/include/X11/ConvertI.h"
libXt-devel_files += "/usr/include/X11/Core.h"
libXt-devel_files += "/usr/include/X11/CoreP.h"
libXt-devel_files += "/usr/include/X11/CreateI.h"
libXt-devel_files += "/usr/include/X11/EventI.h"
libXt-devel_files += "/usr/include/X11/HookObjI.h"
libXt-devel_files += "/usr/include/X11/InitialI.h"
libXt-devel_files += "/usr/include/X11/Intrinsic.h"
libXt-devel_files += "/usr/include/X11/IntrinsicI.h"
libXt-devel_files += "/usr/include/X11/IntrinsicP.h"
libXt-devel_files += "/usr/include/X11/Object.h"
libXt-devel_files += "/usr/include/X11/ObjectP.h"
libXt-devel_files += "/usr/include/X11/PassivGraI.h"
libXt-devel_files += "/usr/include/X11/RectObj.h"
libXt-devel_files += "/usr/include/X11/RectObjP.h"
libXt-devel_files += "/usr/include/X11/ResConfigP.h"
libXt-devel_files += "/usr/include/X11/ResourceI.h"
libXt-devel_files += "/usr/include/X11/SelectionI.h"
libXt-devel_files += "/usr/include/X11/Shell.h"
libXt-devel_files += "/usr/include/X11/ShellI.h"
libXt-devel_files += "/usr/include/X11/ShellP.h"
libXt-devel_files += "/usr/include/X11/StringDefs.h"
libXt-devel_files += "/usr/include/X11/ThreadsI.h"
libXt-devel_files += "/usr/include/X11/TranslateI.h"
libXt-devel_files += "/usr/include/X11/VarargsI.h"
libXt-devel_files += "/usr/include/X11/Vendor.h"
libXt-devel_files += "/usr/include/X11/VendorP.h"
libXt-devel_files += "/usr/include/X11/Xtos.h"
libXt-devel_files += "/usr/lib/libXt.so"
libXt-devel_files += "/usr/lib/pkgconfig/xt.pc"

libXt_files = ""
libXt_files += "libXt.manifest"
libXt_files += "/usr/lib/libXt.so.6"
libXt_files += "/usr/lib/libXt.so.6.0.0"
libXt_files += "/usr/share/X11/app-defaults"

FILES_${PN}-devel = "${libXt-devel_files}"
FILES_${PN} = "${libXt_files}"

PKG_libXt-devel= "libXt-devel"
PKG_libXt= "libXt"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require libXt-rdepends.inc
require libXt-depends.inc
require libXt-extraconf.inc
