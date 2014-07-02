require aul-1.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/aul-1;tag=2a774153e07a81f3df7e4340d6a206ca4a8115a1;nobranch=1"

BBCLASSEXTEND += " native "

