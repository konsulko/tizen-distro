DESCRIPTION = "User management daemon and client library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "LGPL-2.1+"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libgum-common-devel"
PACKAGES += "gumd"
PACKAGES += "libgum"
PACKAGES += "libgum-common"
PACKAGES += "gumd-doc"
PACKAGES += "libgum-devel"
PACKAGES += "gumd-devel"

libgum-common-devel_files = ""
libgum-common-devel_files += "/usr/include/gum/common/*"
libgum-common-devel_files += "/usr/lib/libgum-common*.so"
libgum-common-devel_files += "/usr/lib/pkgconfig/libgum-common.pc"
libgum-common-devel_files += "/etc/gum.conf"
libgum-common-devel_files += "/usr/share/dbus-1/interfaces/*UserManagement*.xml"

gumd_files = ""
gumd_files += "/usr/share/gumd.manifest"
gumd_files += "AUTHORS COPYING.LIB INSTALL NEWS README"
gumd_files += "/usr/bin/gumd"
gumd_files += "/usr/share/dbus-1/system-services"
gumd_files += "/usr/share/dbus-1/system-services/*UserManagement*.service"
gumd_files += "/etc/dbus-1"
gumd_files += "/etc/dbus-1/system.d"
gumd_files += "/etc/dbus-1/system.d/gumd-dbus.conf"

libgum_files = ""
libgum_files += "/usr/share/libgum.manifest"
libgum_files += "/usr/lib/libgum.so.*"

libgum-common_files = ""
libgum-common_files += "/usr/share/libgum-common.manifest"
libgum-common_files += "/usr/lib/libgum-common*.so.*"

gumd-doc_files = ""
gumd-doc_files += "/usr/share/gtk-doc/html/gumd/*"

libgum-devel_files = ""
libgum-devel_files += "/usr/include/gum/*.h"
libgum-devel_files += "/usr/lib/libgum.so"
libgum-devel_files += "/usr/lib/pkgconfig/libgum.pc"
libgum-devel_files += "/usr/bin/gum-example"

gumd-devel_files = ""
gumd-devel_files += "/usr/lib/pkgconfig/gumd.pc"

FILES_libgum-common-devel = "${libgum-common-devel_files}"
FILES_${PN} = "${gumd_files}"
FILES_libgum = "${libgum_files}"
FILES_libgum-common = "${libgum-common_files}"
FILES_${PN}-doc = "${gumd-doc_files}"
FILES_libgum-devel = "${libgum-devel_files}"
FILES_${PN}-devel = "${gumd-devel_files}"

PKG_libgum-common-devel= "libgum-common-devel"
PKG_gumd= "gumd"
PKG_libgum= "libgum"
PKG_libgum-common= "libgum-common"
PKG_gumd-doc= "gumd-doc"
PKG_libgum-devel= "libgum-devel"
PKG_gumd-devel= "gumd-devel"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require gumd-rdepends.inc
require gumd-depends.inc
require gumd-extraconf.inc
