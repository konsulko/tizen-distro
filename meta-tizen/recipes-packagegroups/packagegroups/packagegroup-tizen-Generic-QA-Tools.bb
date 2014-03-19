SUMMARY = "Generic QA Tools"
DESCRIPTION = "Generic QA Tools"
LICENSE = "MIT"
DEPENDS = "virtual/kernel"
PR = "r1"
inherit packagegroup

PACKAGE_ARCH = "${MACHINE_ARCH}"

RDEPENDS_${PN} = "" 

RDEPENDS_${PN} += "bluez-test"
RDEPENDS_${PN} += "connman-test"
RDEPENDS_${PN} += "dbus-python"
RDEPENDS_${PN} += "dlogutil"
RDEPENDS_${PN} += "eet-tools"
RDEPENDS_${PN} += "gdb"
RDEPENDS_${PN} += "gstreamer-utils"
RDEPENDS_${PN} += "neard-test"
RDEPENDS_${PN} += "ofono-test"
RDEPENDS_${PN} += "python-xml"
RDEPENDS_${PN} += "wget"
RDEPENDS_${PN} += "zypper"
