DESCRIPTION = "X.org libXxf86vm library"
HOMEPAGE = "http://www.x.org"
SECTION = "Graphics/X Window System"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libXxf86vm-devel"
PACKAGES += "libXxf86vm"

libXxf86vm-devel_files = ""
libXxf86vm-devel_files += "libXxf86vm.manifest"
libXxf86vm-devel_files += "/usr/lib/libXxf86vm.so"
libXxf86vm-devel_files += "/usr/lib/pkgconfig/xxf86vm.pc"
libXxf86vm-devel_files += "/usr/include/X11/extensions/xf86vmode.h"

libXxf86vm_files = ""
libXxf86vm_files += "libXxf86vm.manifest"
libXxf86vm_files += "/usr/lib/libXxf86vm.so.1"
libXxf86vm_files += "/usr/lib/libXxf86vm.so.1.0.0"

FILES_${PN}-devel = "${libXxf86vm-devel_files}"
FILES_${PN} = "${libXxf86vm_files}"

PKG_libXxf86vm-devel= "libXxf86vm-devel"
PKG_libXxf86vm= "libXxf86vm"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require libXxf86vm-rdepends.inc
require libXxf86vm-depends.inc
require libXxf86vm-extraconf.inc
