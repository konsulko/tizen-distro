DESCRIPTION = "VMware SVGA video driver for the Xorg X server"
HOMEPAGE = "http://xorg.freedesktop.org/"
SECTION = "System/X11/Servers/XF86_4"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "xf86-video-vmware"

xf86-video-vmware_files = ""
xf86-video-vmware_files += "xf86-video-vmware.manifest"
xf86-video-vmware_files += "COPYING"
xf86-video-vmware_files += "/usr/lib/xorg/modules/drivers"
xf86-video-vmware_files += "/usr/lib/xorg/modules/drivers/vmware_drv.so"
xf86-video-vmware_files += "/usr/share/man/man4/vmware.4.gz"

FILES_${PN} = "${xf86-video-vmware_files}"

PKG_xf86-video-vmware= "xf86-video-vmware"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require xf86-video-vmware-rdepends.inc
require xf86-video-vmware-depends.inc
require xf86-video-vmware-extraconf.inc
