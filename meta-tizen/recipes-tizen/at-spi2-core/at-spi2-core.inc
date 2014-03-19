DESCRIPTION = "Assistive Technology Service Provider Interface - D-Bus based implementation"
HOMEPAGE = "http://www.gnome.org/"
SECTION = "System/Libraries"
LICENSE = "GPL-2.0+"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libatspi0"
PACKAGES += "typelib-1_0-Atspi-2_0"
PACKAGES += "at-spi2-core"
PACKAGES += "at-spi2-core-devel"

libatspi0_files = ""
libatspi0_files += "packaging/at-spi2-core.manifest"
libatspi0_files += "/usr/lib/libatspi.so.0*"

typelib-1_0-Atspi-2_0_files = ""
typelib-1_0-Atspi-2_0_files += "packaging/at-spi2-core.manifest"
typelib-1_0-Atspi-2_0_files += "/usr/lib/girepository-1.0/Atspi-2.0.typelib"

at-spi2-core_files = ""
at-spi2-core_files += "packaging/at-spi2-core.manifest"
at-spi2-core_files += "AUTHORS README"
at-spi2-core_files += "/usr/libexec/at-spi2/at-spi-bus-launcher"
at-spi2-core_files += "/usr/libexec/at-spi2/at-spi2-registryd"
at-spi2-core_files += "/etc/at-spi2/accessibility.conf"
at-spi2-core_files += "/etc/xdg/autostart/at-spi-dbus-bus.desktop"
at-spi2-core_files += "/usr/share/dbus-1/services/org.a11y.atspi.Registry.service"
at-spi2-core_files += "/usr/share/dbus-1/services/org.a11y.Bus.service"

at-spi2-core-devel_files = ""
at-spi2-core-devel_files += "packaging/at-spi2-core.manifest"
at-spi2-core-devel_files += "/usr/include/at-spi-2.0"
at-spi2-core-devel_files += "/usr/lib/libatspi.so"
at-spi2-core-devel_files += "/usr/lib/pkgconfig/atspi-2.pc"
at-spi2-core-devel_files += "/usr/share/gir-1.0/*.gir"
at-spi2-core-devel_files += "/usr/share/gtk-doc/html/libatspi"

FILES_libatspi0 = "${libatspi0_files}"
FILES_typelib-1_0-Atspi-2_0 = "${typelib-1_0-Atspi-2_0_files}"
FILES_${PN} = "${at-spi2-core_files}"
FILES_${PN}-devel = "${at-spi2-core-devel_files}"

PKG_libatspi0= "libatspi0"
PKG_typelib-1_0-Atspi-2_0= "typelib-1_0-Atspi-2_0"
PKG_at-spi2-core= "at-spi2-core"
PKG_at-spi2-core-devel= "at-spi2-core-devel"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require at-spi2-core-rdepends.inc
require at-spi2-core-depends.inc
require at-spi2-core-extraconf.inc
