DESCRIPTION = "Library for developing the application."
HOMEPAGE = "http://nohomepage.org"
SECTION = "HomeTF/Livebox"
LICENSE = "Flora License"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "liblivebox-viewer-devel"
PACKAGES += "liblivebox-viewer"

liblivebox-viewer-devel_files = ""
liblivebox-viewer-devel_files += "/usr/include/livebox-viewer/livebox.h"
liblivebox-viewer-devel_files += "/usr/lib/pkgconfig/*.pc"

liblivebox-viewer_files = ""
liblivebox-viewer_files += "liblivebox-viewer.manifest"
liblivebox-viewer_files += "/usr/lib/*.so*"
liblivebox-viewer_files += "/usr/share/license/*"

FILES_${PN}-devel = "${liblivebox-viewer-devel_files}"
FILES_${PN} = "${liblivebox-viewer_files}"

PKG_liblivebox-viewer-devel= "liblivebox-viewer-devel"
PKG_liblivebox-viewer= "liblivebox-viewer"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require livebox-viewer-rdepends.inc
require livebox-viewer-depends.inc
require livebox-viewer-extraconf.inc
