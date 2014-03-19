DESCRIPTION = "X TrueType font cache extension client library"
HOMEPAGE = "http://xorg.freedesktop.org/"
SECTION = "Development/Libraries"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libXfontcache"
PACKAGES += "libXfontcache-devel"

libXfontcache_files = ""
libXfontcache_files += "libXfontcache.manifest"
libXfontcache_files += "/usr/lib/libXfontcache.so.1*"

libXfontcache-devel_files = ""
libXfontcache-devel_files += "libXfontcache.manifest"
libXfontcache-devel_files += "/usr/lib/libXfontcache.so"
libXfontcache-devel_files += "/usr/lib/pkgconfig/xfontcache.pc"
libXfontcache-devel_files += "/usr/share/man/man3/*"

FILES_${PN} = "${libXfontcache_files}"
FILES_${PN}-devel = "${libXfontcache-devel_files}"

PKG_libXfontcache= "libXfontcache"
PKG_libXfontcache-devel= "libXfontcache-devel"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require libXfontcache-rdepends.inc
require libXfontcache-depends.inc
require libXfontcache-extraconf.inc
