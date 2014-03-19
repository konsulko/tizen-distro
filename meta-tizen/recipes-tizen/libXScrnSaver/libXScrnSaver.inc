DESCRIPTION = "X11 Screen Saver extension client library"
HOMEPAGE = "http://xorg.freedesktop.org/"
SECTION = "Development/Libraries/C and C++"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libXScrnSaver-devel"
PACKAGES += "libXss"

libXScrnSaver-devel_files = ""
libXScrnSaver-devel_files += "libXScrnSaver.manifest"
libXScrnSaver-devel_files += "/usr/include/X11/*"
libXScrnSaver-devel_files += "/usr/lib/libXss.so"
libXScrnSaver-devel_files += "/usr/lib/pkgconfig/xscrnsaver.pc"
libXScrnSaver-devel_files += "/usr/share/man/man3/*"

libXss_files = ""
libXss_files += "libXScrnSaver.manifest"
libXss_files += "/usr/lib/libXss.so.1*"

FILES_${PN}-devel = "${libXScrnSaver-devel_files}"
FILES_libXss = "${libXss_files}"

PKG_libXScrnSaver-devel= "libXScrnSaver-devel"
PKG_libXss= "libXss"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require libXScrnSaver-rdepends.inc
require libXScrnSaver-depends.inc
require libXScrnSaver-extraconf.inc
