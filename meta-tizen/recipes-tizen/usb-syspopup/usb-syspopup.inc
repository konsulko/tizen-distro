DESCRIPTION = "USB system popup"
HOMEPAGE = "http://nohomepage.org"
SECTION = "framework-system"
LICENSE = "APLv2"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "org.tizen.usb-syspopup"
PACKAGES += "org.tizen.usbotg-syspopup"

org.tizen.usb-syspopup_files = ""
org.tizen.usb-syspopup_files += "org.tizen.usb-syspopup.manifest"
org.tizen.usb-syspopup_files += "/usr/share/packages/org.tizen.usb-syspopup.xml"

org.tizen.usbotg-syspopup_files = ""
org.tizen.usbotg-syspopup_files += "org.tizen.usb-syspopup.manifest"
org.tizen.usbotg-syspopup_files += "/usr/share/packages/org.tizen.usbotg-syspopup.xml"

FILES_${PN} = "${org.tizen.usb-syspopup_files}"
FILES_org.tizen.usbotg-syspopup = "${org.tizen.usbotg-syspopup_files}"

PKG_org.tizen.usb-syspopup= "org.tizen.usb-syspopup"
PKG_org.tizen.usbotg-syspopup= "org.tizen.usbotg-syspopup"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require usb-syspopup-rdepends.inc
require usb-syspopup-depends.inc
require usb-syspopup-extraconf.inc
