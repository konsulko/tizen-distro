require rpm.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/rpm;tag=fbac5c17e9f395d436a0dd57ce2e4ceda758d756;nobranch=1"

BBCLASSEXTEND += " native "

