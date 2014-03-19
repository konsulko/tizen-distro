DESCRIPTION = "X.Org X11 Protocol gestureproto"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Development/System"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "xorg-x11-proto-gesture"

xorg-x11-proto-gesture_files = ""
xorg-x11-proto-gesture_files += "xorg-x11-proto-gesture.manifest"
xorg-x11-proto-gesture_files += "/usr/include/X11/extensions/*.h"
xorg-x11-proto-gesture_files += "/usr/share/pkgconfig/*.pc"

FILES_${PN} = "${xorg-x11-proto-gesture_files}"

PKG_xorg-x11-proto-gesture= "xorg-x11-proto-gesture"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require x11proto-gesture-rdepends.inc
require x11proto-gesture-depends.inc
require x11proto-gesture-extraconf.inc
