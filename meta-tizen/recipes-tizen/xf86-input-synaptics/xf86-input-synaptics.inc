DESCRIPTION = "Synaptics touchpad input driver for the Xorg X server"
HOMEPAGE = "http://xorg.freedesktop.org/"
SECTION = "System/X11/Servers/XF86_4"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "xf86-input-synaptics"
PACKAGES += "xf86-input-synaptics-devel"

xf86-input-synaptics_files = ""
xf86-input-synaptics_files += "xf86-input-synaptics.manifest"
xf86-input-synaptics_files += "COPYING README"
xf86-input-synaptics_files += "/etc/X11/xorg.conf.d/50-synaptics.conf"
xf86-input-synaptics_files += "/usr/lib/xorg/modules/input"
xf86-input-synaptics_files += "/usr/lib/xorg/modules/input/synaptics_drv.so"
xf86-input-synaptics_files += "/usr/bin/synclient"
xf86-input-synaptics_files += "/usr/bin/syndaemon"

xf86-input-synaptics-devel_files = ""
xf86-input-synaptics-devel_files += "xf86-input-synaptics.manifest"
xf86-input-synaptics-devel_files += "/usr/include/xorg/synaptics.h"
xf86-input-synaptics-devel_files += "/usr/include/xorg/synaptics-properties.h"
xf86-input-synaptics-devel_files += "/usr/lib/pkgconfig/xorg-synaptics.pc"

FILES_${PN} = "${xf86-input-synaptics_files}"
FILES_${PN}-devel = "${xf86-input-synaptics-devel_files}"

PKG_xf86-input-synaptics= "xf86-input-synaptics"
PKG_xf86-input-synaptics-devel= "xf86-input-synaptics-devel"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require xf86-input-synaptics-rdepends.inc
require xf86-input-synaptics-depends.inc
require xf86-input-synaptics-extraconf.inc
