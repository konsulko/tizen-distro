DESCRIPTION = "Framebuffer video driver for the Xorg X server"
HOMEPAGE = "http://xorg.freedesktop.org/"
SECTION = "System/X11/Servers/XF86_4"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "xf86-video-fbdev"

xf86-video-fbdev_files = ""
xf86-video-fbdev_files += "xf86-video-fbdev.manifest"
xf86-video-fbdev_files += "COPYING"
xf86-video-fbdev_files += "/usr/lib/xorg/modules/drivers"
xf86-video-fbdev_files += "/usr/lib/xorg/modules/drivers/fbdev_drv.so"
xf86-video-fbdev_files += "/usr/share/man/man4/fbdev.4.gz"

FILES_${PN} = "${xf86-video-fbdev_files}"

PKG_xf86-video-fbdev= "xf86-video-fbdev"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require xf86-video-fbdev-rdepends.inc
require xf86-video-fbdev-depends.inc
require xf86-video-fbdev-extraconf.inc
