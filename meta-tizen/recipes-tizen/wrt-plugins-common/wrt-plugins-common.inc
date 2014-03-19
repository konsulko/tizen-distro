DESCRIPTION = "wrt-plugins common library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Development/Libraries"
LICENSE = "Apache-2.0"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "wrt-plugins-common-devel"
PACKAGES += "wrt-plugins-common"

wrt-plugins-common-devel_files = ""
wrt-plugins-common-devel_files += "wrt-plugins-common.manifest"
wrt-plugins-common-devel_files += "/usr/include/*"
wrt-plugins-common-devel_files += "/usr/lib/pkgconfig/*"

wrt-plugins-common_files = ""
wrt-plugins-common_files += "wrt-plugins-common.manifest"
wrt-plugins-common_files += "/usr/etc/wrt-plugins/config.dtd"
wrt-plugins-common_files += "/usr/lib/*.so"
wrt-plugins-common_files += "/usr/lib/*.so.*"
wrt-plugins-common_files += "/usr/lib/wrt-plugins/w3c-widget-interface/libwrt-plugins-w3c-widget-interface.so"
wrt-plugins-common_files += "/usr/share/license/wrt-plugins-common"
wrt-plugins-common_files += "/etc/smack/accesses2.d/wrt-popup-ace-runtime.rule"
wrt-plugins-common_files += "/etc/smack/accesses2.d/wrt-popup-wrt-runtime.rule"
wrt-plugins-common_files += "/opt/etc/smack/accesses.d/wrt-popup-ace-runtime.rule"
wrt-plugins-common_files += "/opt/etc/smack/accesses.d/wrt-popup-wrt-runtime.rule"
wrt-plugins-common_files += "/etc/ld.so.conf.d/wrt-plugins-common.conf"

FILES_${PN}-devel = "${wrt-plugins-common-devel_files}"
FILES_${PN} = "${wrt-plugins-common_files}"

PKG_wrt-plugins-common-devel= "wrt-plugins-common-devel"
PKG_wrt-plugins-common= "wrt-plugins-common"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require wrt-plugins-common-rdepends.inc
require wrt-plugins-common-depends.inc
require wrt-plugins-common-extraconf.inc
