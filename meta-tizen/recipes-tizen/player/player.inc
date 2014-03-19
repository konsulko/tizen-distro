DESCRIPTION = "A Media Player library in Tizen Native API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Multimedia/API"
LICENSE = "Apache-2.0"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "capi-media-player"
PACKAGES += "capi-media-player-devel"

capi-media-player_files = ""
capi-media-player_files += "capi-media-player.manifest"
capi-media-player_files += "capi-media-player.manifest"
capi-media-player_files += "/usr/lib/libcapi-media-player.so.*"
capi-media-player_files += "/usr/share/license/capi-media-player"
capi-media-player_files += "/usr/bin/*"

capi-media-player-devel_files = ""
capi-media-player-devel_files += "capi-media-player.manifest"
capi-media-player-devel_files += "/usr/include/media/*.h"
capi-media-player-devel_files += "/usr/lib/pkgconfig/*.pc"
capi-media-player-devel_files += "/usr/lib/libcapi-media-player.so"

FILES_${PN} = "${capi-media-player_files}"
FILES_${PN}-devel = "${capi-media-player-devel_files}"

PKG_capi-media-player= "capi-media-player"
PKG_capi-media-player-devel= "capi-media-player-devel"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require player-rdepends.inc
require player-depends.inc
require player-extraconf.inc
