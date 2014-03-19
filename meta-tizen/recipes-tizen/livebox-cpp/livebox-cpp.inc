DESCRIPTION = "C++ adaptor for a livebox"
HOMEPAGE = "http://nohomepage.org"
SECTION = "HomeTF/Livebox"
LICENSE = "Flora License"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "liblivebox-cpp"
PACKAGES += "liblivebox-cpp-devel"

liblivebox-cpp_files = ""
liblivebox-cpp_files += "liblivebox-cpp.manifest"
liblivebox-cpp_files += "/usr/lib/*.so*"
liblivebox-cpp_files += "/usr/share/license/*"

liblivebox-cpp-devel_files = ""
liblivebox-cpp-devel_files += "liblivebox-cpp.manifest"
liblivebox-cpp-devel_files += "/usr/include/livebox-cpp/livebox-cpp.h"
liblivebox-cpp-devel_files += "/usr/share/doc/livebox-cpp/livebox-cpp_PG.h"
liblivebox-cpp-devel_files += "/usr/lib/pkgconfig/*.pc"

FILES_${PN} = "${liblivebox-cpp_files}"
FILES_${PN}-devel = "${liblivebox-cpp-devel_files}"

PKG_liblivebox-cpp= "liblivebox-cpp"
PKG_liblivebox-cpp-devel= "liblivebox-cpp-devel"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require livebox-cpp-rdepends.inc
require livebox-cpp-depends.inc
require livebox-cpp-extraconf.inc
