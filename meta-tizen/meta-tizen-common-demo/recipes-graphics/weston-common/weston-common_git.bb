require weston-common.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/common/weston-common;tag=9d65c22f3814f85b6365dd81a5768dcff0bf60a2;nobranch=1"

BBCLASSEXTEND += " native "

