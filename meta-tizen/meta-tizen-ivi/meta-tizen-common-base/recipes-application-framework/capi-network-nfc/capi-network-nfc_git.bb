require capi-network-nfc.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/nfc;tag=97257ca5d438a8cc92aab39e70041920fd3e4d2f;nobranch=1"

BBCLASSEXTEND += " native "

