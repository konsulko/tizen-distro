DESCRIPTION = "X.Org X11 Protocol xf86driproto"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Development/System"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "xf86driproto"

xf86driproto_files = ""
xf86driproto_files += "xf86driproto.manifest"
xf86driproto_files += "/usr/include/X11/dri/*.h"
xf86driproto_files += "/usr/share/pkgconfig/*.pc"

FILES_${PN} = "${xf86driproto_files}"

PKG_xf86driproto= "xf86driproto"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require xf86driproto-rdepends.inc
require xf86driproto-depends.inc
require xf86driproto-extraconf.inc
