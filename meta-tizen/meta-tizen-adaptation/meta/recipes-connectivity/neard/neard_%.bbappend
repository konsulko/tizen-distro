SECTION = "Connectivity/NFC"

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

# Tizen patches
SRC_URI += "file://0001-ndef-Support-RAW-ndef-writes.patch"
SRC_URI += "file://0002-tag-Implement-a-raw-NDEF-accessor.patch"
SRC_URI += "file://0003-Add-raw-NDEF-support-for-P2P.patch"
SRC_URI += "file://0004-ndef-Add-support-for-WiFi-Handover-through-MIME-x-nf.patch"
SRC_URI += "file://0005-Add-packaging-directory.patch"

# Use bluez5 instead of bluez4
RRECOMMENDS_${PN}_remove = "bluez4"
RRECOMMENDS_${PN} += "${@bb.utils.contains('DISTRO_FEATURES', 'bluetooth', 'bluez5', '', d)}"

EXTRA_OECONF += "--enable-test"

FILES_${PN}-tests += "${libdir}/${BPN}/test/*"
