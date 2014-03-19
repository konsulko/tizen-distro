DESCRIPTION = "X.Org X11 libXxf86dga runtime library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libXxf86dga-devel"
PACKAGES += "libXxf86dga"

libXxf86dga-devel_files = ""
libXxf86dga-devel_files += "libXxf86dga.manifest"
libXxf86dga-devel_files += "/usr/lib/libXxf86dga.so"
libXxf86dga-devel_files += "/usr/lib/pkgconfig/xxf86dga.pc"
libXxf86dga-devel_files += "/usr/include/X11/extensions/xf86dga1.h"
libXxf86dga-devel_files += "/usr/include/X11/extensions/Xxf86dga.h"

libXxf86dga_files = ""
libXxf86dga_files += "libXxf86dga.manifest"
libXxf86dga_files += "/usr/lib/libXxf86dga.so.1"
libXxf86dga_files += "/usr/lib/libXxf86dga.so.1.0.0"

FILES_${PN}-devel = "${libXxf86dga-devel_files}"
FILES_${PN} = "${libXxf86dga_files}"

PKG_libXxf86dga-devel= "libXxf86dga-devel"
PKG_libXxf86dga= "libXxf86dga"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require libXxf86dga-rdepends.inc
require libXxf86dga-depends.inc
require libXxf86dga-extraconf.inc
