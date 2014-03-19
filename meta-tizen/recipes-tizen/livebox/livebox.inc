DESCRIPTION = "Library for the development of a livebox"
HOMEPAGE = "http://nohomepage.org"
SECTION = "HomeTF/Livebox"
LICENSE = "Flora License"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "liblivebox"
PACKAGES += "liblivebox-devel"

liblivebox_files = ""
liblivebox_files += "liblivebox.manifest"
liblivebox_files += "/usr/lib/*.so*"
liblivebox_files += "/usr/share/license/*"

liblivebox-devel_files = ""
liblivebox-devel_files += "liblivebox.manifest"
liblivebox-devel_files += "/usr/include/livebox/livebox.h"
liblivebox-devel_files += "/usr/lib/pkgconfig/*.pc"

FILES_${PN} = "${liblivebox_files}"
FILES_${PN}-devel = "${liblivebox-devel_files}"

PKG_liblivebox= "liblivebox"
PKG_liblivebox-devel= "liblivebox-devel"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require livebox-rdepends.inc
require livebox-depends.inc
require livebox-extraconf.inc
