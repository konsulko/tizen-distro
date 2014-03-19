DESCRIPTION = "X.Org X11 DMX runtime library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System Environment/Libraries"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libdmx"
PACKAGES += "libdmx-devel"

libdmx_files = ""
libdmx_files += "libdmx.manifest"
libdmx_files += "/usr/share/license/libdmx"
libdmx_files += "/usr/lib/libdmx.so.1"
libdmx_files += "/usr/lib/libdmx.so.1.0.0"

libdmx-devel_files = ""
libdmx-devel_files += "libdmx.manifest"
libdmx-devel_files += "/usr/lib/libdmx.so"
libdmx-devel_files += "/usr/lib/pkgconfig/dmx.pc"
libdmx-devel_files += "/usr/include/X11/extensions/dmxext.h"

FILES_${PN} = "${libdmx_files}"
FILES_${PN}-devel = "${libdmx-devel_files}"

PKG_libdmx= "libdmx"
PKG_libdmx-devel= "libdmx-devel"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require libdmx-rdepends.inc
require libdmx-depends.inc
require libdmx-extraconf.inc
