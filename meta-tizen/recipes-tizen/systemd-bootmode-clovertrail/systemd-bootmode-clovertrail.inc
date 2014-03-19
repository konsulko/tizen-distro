DESCRIPTION = "Boot mode selector for systemd"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Base"
LICENSE = "Not Copyrightable"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "systemd-bootmode"

systemd-bootmode_files = ""
systemd-bootmode_files += "systemd-bootmode.manifest"
systemd-bootmode_files += "/usr/lib/systemd/system/bootmode.target"
systemd-bootmode_files += "/usr/lib/systemd/system/bootmode-graphical.service"
systemd-bootmode_files += "/usr/lib/systemd/system/bootmode-charging.service"
systemd-bootmode_files += "/usr/lib/systemd/system/bootmode.target.wants"
systemd-bootmode_files += "/usr/lib/systemd/system/bootmode.target.wants/bootmode-graphical.service"
systemd-bootmode_files += "/usr/lib/systemd/system/bootmode.target.wants/bootmode-charging.service"

FILES_${PN} = "${systemd-bootmode_files}"

PKG_systemd-bootmode= "systemd-bootmode"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require systemd-bootmode-clovertrail-rdepends.inc
require systemd-bootmode-clovertrail-depends.inc
require systemd-bootmode-clovertrail-extraconf.inc
