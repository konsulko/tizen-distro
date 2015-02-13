require capi-network-tethering.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/tethering;tag=64e19e65e8ea1085b281af93aa25e40aba9145df;nobranch=1"

BBCLASSEXTEND += " native "

