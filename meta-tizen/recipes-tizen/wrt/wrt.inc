DESCRIPTION = "web runtime"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Development/Libraries"
LICENSE = "Apache-2.0"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "wrt-devel"
PACKAGES += "wrt"

wrt-devel_files = ""
wrt-devel_files += "wrt.manifest"
wrt-devel_files += "/usr/include/*"
wrt-devel_files += "/usr/lib/pkgconfig/*"

wrt_files = ""
wrt_files += "wrt.manifest"
wrt_files += "/usr/lib/*.so"
wrt_files += "/usr/lib/*.so.*"
wrt_files += "/usr/share/wrt-engine/*"
wrt_files += "/usr/share/license/wrt"
wrt_files += "/usr/share/aul/preload_list_wrt.txt"
wrt_files += "/usr/lib/systemd/system/graphical.target.wants/wrt_launchpad_daemon@app.service"
wrt_files += "/usr/lib/systemd/system/wrt_launchpad_daemon@.service"
wrt_files += "/usr/lib/systemd/system/sockets.target.wants/wrt_launchpad_daemon_1.socket"
wrt_files += "/usr/lib/systemd/system/wrt_launchpad_daemon_1.socket"
wrt_files += "/usr/lib/systemd/system/sockets.target.wants/wrt_launchpad_daemon_2.socket"
wrt_files += "/usr/lib/systemd/system/wrt_launchpad_daemon_2.socket"

FILES_${PN}-devel = "${wrt-devel_files}"
FILES_${PN} = "${wrt_files}"

PKG_wrt-devel= "wrt-devel"
PKG_wrt= "wrt"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require wrt-rdepends.inc
require wrt-depends.inc
require wrt-extraconf.inc
