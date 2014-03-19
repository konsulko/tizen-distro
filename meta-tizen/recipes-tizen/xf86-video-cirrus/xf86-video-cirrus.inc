DESCRIPTION = "Cirrus Logic video driver for the Xorg X server"
HOMEPAGE = "http://xorg.freedesktop.org/"
SECTION = "System/X11/Servers/XF86_4"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "xf86-video-cirrus"

xf86-video-cirrus_files = ""
xf86-video-cirrus_files += "xf86-video-cirrus.manifest"
xf86-video-cirrus_files += "COPYING"
xf86-video-cirrus_files += "/usr/lib/xorg/modules/drivers"
xf86-video-cirrus_files += "/usr/lib/xorg/modules/drivers/cirrus_alpine.so"
xf86-video-cirrus_files += "/usr/lib/xorg/modules/drivers/cirrus_laguna.so"
xf86-video-cirrus_files += "/usr/lib/xorg/modules/drivers/cirrus_drv.so"
xf86-video-cirrus_files += "/usr/share/man/man4/cirrus.4.gz"

FILES_${PN} = "${xf86-video-cirrus_files}"

PKG_xf86-video-cirrus= "xf86-video-cirrus"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require xf86-video-cirrus-rdepends.inc
require xf86-video-cirrus-depends.inc
require xf86-video-cirrus-extraconf.inc
