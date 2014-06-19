require pam.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/pam;tag=f879c183094dea0636c195bd96b96c2c00f32559;nobranch=1"

BBCLASSEXTEND += " native "

