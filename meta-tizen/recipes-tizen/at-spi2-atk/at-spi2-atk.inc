DESCRIPTION = "Assistive Technology Service Provider Interface - GTK+ module"
HOMEPAGE = "http://www.gnome.org/"
SECTION = "System/Libraries"
LICENSE = "LGPL-2.0+"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libatk-bridge-2_0-0"
PACKAGES += "at-spi2-atk-devel"

libatk-bridge-2_0-0_files = ""
libatk-bridge-2_0-0_files += "packaging/at-spi2-atk.manifest"
libatk-bridge-2_0-0_files += "/usr/lib/libatk-bridge-2.0.so.*"
libatk-bridge-2_0-0_files += "/usr/share/glib-2.0/schemas/org.a11y.atspi.gschema.xml"
libatk-bridge-2_0-0_files += "/usr/lib/gtk-2.0/modules/libatk-bridge.so"

at-spi2-atk-devel_files = ""
at-spi2-atk-devel_files += "packaging/at-spi2-atk.manifest"
at-spi2-atk-devel_files += "/usr/include/at-spi2-atk/2.0/atk-bridge.h"
at-spi2-atk-devel_files += "/usr/lib/libatk-bridge-2.0.so"
at-spi2-atk-devel_files += "/usr/lib/pkgconfig/atk-bridge-2.0.pc"

FILES_libatk-bridge-2_0-0 = "${libatk-bridge-2_0-0_files}"
FILES_${PN}-devel = "${at-spi2-atk-devel_files}"

PKG_libatk-bridge-2_0-0= "libatk-bridge-2_0-0"
PKG_at-spi2-atk-devel= "at-spi2-atk-devel"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require at-spi2-atk-rdepends.inc
require at-spi2-atk-depends.inc
require at-spi2-atk-extraconf.inc
