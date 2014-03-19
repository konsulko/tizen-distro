DESCRIPTION = "JavaScript plugins for WebRuntime"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Development/Libraries"
LICENSE = "Apache-2.0"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "wrt-plugins-tizen-devel"
PACKAGES += "wrt-plugins-tizen"

wrt-plugins-tizen-devel_files = ""
wrt-plugins-tizen-devel_files += "/usr/include/*"
wrt-plugins-tizen-devel_files += "/usr/lib/pkgconfig/*"

wrt-plugins-tizen_files = ""
wrt-plugins-tizen_files += "wrt-plugins-tizen.manifest "
wrt-plugins-tizen_files += "/usr/lib/wrt-plugins/*"
wrt-plugins-tizen_files += "/usr/etc/tizen-apis/*"
wrt-plugins-tizen_files += "/etc/ld.so.conf.d/wrt-plugins-tizen.conf"

FILES_${PN}-devel = "${wrt-plugins-tizen-devel_files}"
FILES_${PN} = "${wrt-plugins-tizen_files}"

PKG_wrt-plugins-tizen-devel= "wrt-plugins-tizen-devel"
PKG_wrt-plugins-tizen= "wrt-plugins-tizen"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require wrt-plugins-tizen-rdepends.inc
require wrt-plugins-tizen-depends.inc
require wrt-plugins-tizen-extraconf.inc
