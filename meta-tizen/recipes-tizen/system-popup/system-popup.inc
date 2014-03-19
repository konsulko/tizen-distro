DESCRIPTION = "System Popup application (poweroff popup,sysevent-alert)"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Utilities"
LICENSE = "Apache-2.0"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "system-popup"
PACKAGES += "org.tizen.poweroff-syspopup"
PACKAGES += "org.tizen.lowbat-syspopup"
PACKAGES += "org.tizen.usb-syspopup"
PACKAGES += "org.tizen.lowmem-syspopup"
PACKAGES += "org.tizen.usbotg-syspopup"
PACKAGES += "org.tizen.mmc-syspopup"

system-popup_files = ""
system-popup_files += "system-popup.manifest"

org.tizen.poweroff-syspopup_files = ""
org.tizen.poweroff-syspopup_files += "system-popup.manifest"
org.tizen.poweroff-syspopup_files += "/usr/apps/org.tizen.poweroff-syspopup/bin/poweroff-popup"
org.tizen.poweroff-syspopup_files += "/usr/apps/org.tizen.poweroff-syspopup/res/edje/poweroff/poweroff.edj"
org.tizen.poweroff-syspopup_files += "/usr/apps/org.tizen.poweroff-syspopup/res/icon/org.tizen.poweroff-syspopup.png"
org.tizen.poweroff-syspopup_files += "/usr/share/packages/org.tizen.poweroff-syspopup.xml"
org.tizen.poweroff-syspopup_files += "/usr/share/process-info/poweroff-popup.ini"
org.tizen.poweroff-syspopup_files += "/usr/apps/org.tizen.poweroff-syspopup/res/locale/*/LC_MESSAGES/*.mo"
org.tizen.poweroff-syspopup_files += "/opt/etc/smack/accesses.d/org.tizen.poweroff-syspopup.rule"

org.tizen.lowbat-syspopup_files = ""
org.tizen.lowbat-syspopup_files += "system-popup.manifest"
org.tizen.lowbat-syspopup_files += "/usr/apps/org.tizen.lowbat-syspopup/bin/lowbatt-popup"
org.tizen.lowbat-syspopup_files += "/usr/apps/org.tizen.lowbat-syspopup/res/edje/lowbatt/lowbatt.edj"
org.tizen.lowbat-syspopup_files += "/usr/apps/org.tizen.lowbat-syspopup/res/locale/*/LC_MESSAGES/*.mo"
org.tizen.lowbat-syspopup_files += "/usr/apps/org.tizen.lowbat-syspopup/res/icon/org.tizen.lowbat-syspopup.png"
org.tizen.lowbat-syspopup_files += "/usr/share/packages/org.tizen.lowbat-syspopup.xml"
org.tizen.lowbat-syspopup_files += "/usr/share/process-info/lowbatt-popup.ini"
org.tizen.lowbat-syspopup_files += "/opt/etc/smack/accesses.d/org.tizen.lowbat-syspopup.rule"

org.tizen.usb-syspopup_files = ""
org.tizen.usb-syspopup_files += "system-popup.manifest"
org.tizen.usb-syspopup_files += "/usr/share/packages/org.tizen.usb-syspopup.xml"
org.tizen.usb-syspopup_files += "/opt/etc/smack/accesses.d/org.tizen.usb-syspopup.rule"

org.tizen.lowmem-syspopup_files = ""
org.tizen.lowmem-syspopup_files += "system-popup.manifest"
org.tizen.lowmem-syspopup_files += "/usr/apps/org.tizen.lowmem-syspopup/bin/lowmem-popup"
org.tizen.lowmem-syspopup_files += "/usr/apps/org.tizen.lowmem-syspopup/res/keysound/02_Warning.wav"
org.tizen.lowmem-syspopup_files += "/usr/apps/org.tizen.lowmem-syspopup/res/edje/lowmem/lowmem.edj"
org.tizen.lowmem-syspopup_files += "/usr/apps/org.tizen.lowmem-syspopup/res/icon/org.tizen.lowmem-syspopup.png"
org.tizen.lowmem-syspopup_files += "/usr/share/packages/org.tizen.lowmem-syspopup.xml"
org.tizen.lowmem-syspopup_files += "/usr/share/process-info/lowmem-popup.ini"
org.tizen.lowmem-syspopup_files += "/usr/apps/org.tizen.lowmem-syspopup/res/locale/*/LC_MESSAGES/*.mo"
org.tizen.lowmem-syspopup_files += "/opt/etc/smack/accesses.d/org.tizen.lowmem-syspopup.rule"

org.tizen.usbotg-syspopup_files = ""
org.tizen.usbotg-syspopup_files += "system-popup.manifest"
org.tizen.usbotg-syspopup_files += "/usr/share/packages/org.tizen.usbotg-syspopup.xml"
org.tizen.usbotg-syspopup_files += "/opt/etc/smack/accesses.d/org.tizen.usbotg-syspopup.rule"

org.tizen.mmc-syspopup_files = ""
org.tizen.mmc-syspopup_files += "system-popup.manifest"
org.tizen.mmc-syspopup_files += "/usr/apps/org.tizen.mmc-syspopup/bin/mmc-popup"
org.tizen.mmc-syspopup_files += "/usr/share/packages/org.tizen.mmc-syspopup.xml"
org.tizen.mmc-syspopup_files += "/usr/share/process-info/mmc-popup.ini"
org.tizen.mmc-syspopup_files += "/usr/apps/org.tizen.mmc-syspopup/res/locale/*/LC_MESSAGES/*.mo"
org.tizen.mmc-syspopup_files += "/opt/etc/smack/accesses.d/org.tizen.mmc-syspopup.rule"

FILES_${PN} = "${system-popup_files}"
FILES_org.tizen.poweroff-syspopup = "${org.tizen.poweroff-syspopup_files}"
FILES_org.tizen.lowbat-syspopup = "${org.tizen.lowbat-syspopup_files}"
FILES_org.tizen.usb-syspopup = "${org.tizen.usb-syspopup_files}"
FILES_org.tizen.lowmem-syspopup = "${org.tizen.lowmem-syspopup_files}"
FILES_org.tizen.usbotg-syspopup = "${org.tizen.usbotg-syspopup_files}"
FILES_org.tizen.mmc-syspopup = "${org.tizen.mmc-syspopup_files}"

PKG_system-popup= "system-popup"
PKG_org.tizen.poweroff-syspopup= "org.tizen.poweroff-syspopup"
PKG_org.tizen.lowbat-syspopup= "org.tizen.lowbat-syspopup"
PKG_org.tizen.usb-syspopup= "org.tizen.usb-syspopup"
PKG_org.tizen.lowmem-syspopup= "org.tizen.lowmem-syspopup"
PKG_org.tizen.usbotg-syspopup= "org.tizen.usbotg-syspopup"
PKG_org.tizen.mmc-syspopup= "org.tizen.mmc-syspopup"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require system-popup-rdepends.inc
require system-popup-depends.inc
require system-popup-extraconf.inc
