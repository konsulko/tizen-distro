require pam.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/pam;tag=8e4294bb11020f6ba798fb1fdc460beaf0a47c31;nobranch=1"

BBCLASSEXTEND += " native "

