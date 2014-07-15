require pam.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/pam;tag=7d469347460af24cf68c6ef1fa72e8aaec5a1a3b;nobranch=1"

BBCLASSEXTEND += " native "

