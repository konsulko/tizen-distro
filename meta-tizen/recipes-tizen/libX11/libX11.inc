DESCRIPTION = "Core X11 protocol client library"
HOMEPAGE = "http://xorg.freedesktop.org/"
SECTION = "Graphics/X Window System"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libX11-docs"
PACKAGES += "libX11-data"
PACKAGES += "libX11-xcb"
PACKAGES += "libX11"
PACKAGES += "libX11-devel"

libX11-docs_files = ""
libX11-docs_files += "/usr/share/info"
libX11-docs_files += "/usr/share/man"

libX11-data_files = ""
libX11-data_files += "libX11.manifest"
libX11-data_files += "/usr/share/X11"

libX11-xcb_files = ""
libX11-xcb_files += "libX11.manifest"
libX11-xcb_files += "/usr/lib/libX11-xcb.so.1*"

libX11_files = ""
libX11_files += "libX11.manifest"
libX11_files += "/usr/lib/libX11.so.6*"

libX11-devel_files = ""
libX11-devel_files += "libX11.manifest"
libX11-devel_files += "/usr/include/X11/*"
libX11-devel_files += "/usr/lib/*.so"
libX11-devel_files += "/usr/lib/pkgconfig/*.pc"
libX11-devel_files += "/usr/share/doc/packages/libX11"

FILES_${PN}-docs = "${libX11-docs_files}"
FILES_${PN}-data = "${libX11-data_files}"
FILES_${PN}-xcb = "${libX11-xcb_files}"
FILES_${PN} = "${libX11_files}"
FILES_${PN}-devel = "${libX11-devel_files}"

PKG_libX11-docs= "libX11-docs"
PKG_libX11-data= "libX11-data"
PKG_libX11-xcb= "libX11-xcb"
PKG_libX11= "libX11"
PKG_libX11-devel= "libX11-devel"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require libX11-rdepends.inc
require libX11-depends.inc
require libX11-extraconf.inc
