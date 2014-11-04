require desktop-skin.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/common/desktop-skin;tag=ac4f1b6b5e6021c5ef6e9e3033e06215d4ba1274;nobranch=1"

BBCLASSEXTEND += " native "

