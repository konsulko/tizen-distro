require murphy.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/murphy;tag=4513081acc01ce47e88f2e6ab6f453dba734d2ed;nobranch=1"

BBCLASSEXTEND += " native "

