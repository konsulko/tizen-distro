FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

# Tizen patches
SRC_URI += "file://0001-ndef-Support-RAW-ndef-writes.patch"
SRC_URI += "file://0002-tag-Implement-a-raw-NDEF-accessor.patch"
SRC_URI += "file://0003-Add-raw-NDEF-support-for-P2P.patch"
SRC_URI += "file://0004-ndef-Add-support-for-WiFi-Handover-through-MIME-x-nf.patch"
SRC_URI += "file://0005-Add-packaging-directory.patch"
