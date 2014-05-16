require weston-common.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/common/weston-common;tag=eb16165b7bcdb503a9e17e4ea9377d7e6359f5f0;nobranch=1"

BBCLASSEXTEND += " native "

