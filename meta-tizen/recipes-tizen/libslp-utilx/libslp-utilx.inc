DESCRIPTION = "utilX"
HOMEPAGE = "http://nohomepage.org"
SECTION = "UI Framework/Libraries"
LICENSE = "Apache-2.0"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libslp-utilx-devel"
PACKAGES += "libslp-utilx"

libslp-utilx-devel_files = ""
libslp-utilx-devel_files += "libslp-utilx.manifest"
libslp-utilx-devel_files += "/usr/include/utilX.h"
libslp-utilx-devel_files += "/usr/lib/libutilX.so"
libslp-utilx-devel_files += "/usr/lib/pkgconfig/utilX.pc"

libslp-utilx_files = ""
libslp-utilx_files += "libslp-utilx.manifest"
libslp-utilx_files += "/usr/lib/libutilX.so.*"
libslp-utilx_files += "/usr/share/license/libslp-utilx"

FILES_${PN}-devel = "${libslp-utilx-devel_files}"
FILES_${PN} = "${libslp-utilx_files}"

PKG_libslp-utilx-devel= "libslp-utilx-devel"
PKG_libslp-utilx= "libslp-utilx"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require libslp-utilx-rdepends.inc
require libslp-utilx-depends.inc
require libslp-utilx-extraconf.inc
