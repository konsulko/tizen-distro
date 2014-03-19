DESCRIPTION = "Intel Driver for Video Acceleration (VA) API for Linux"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libva-intel-driver"

libva-intel-driver_files = ""
libva-intel-driver_files += "/usr/lib/dri/i965_drv_video.so"

FILES_${PN} = "${libva-intel-driver_files}"

PKG_libva-intel-driver= "libva-intel-driver"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require libva-intel-driver-rdepends.inc
require libva-intel-driver-depends.inc
require libva-intel-driver-extraconf.inc
