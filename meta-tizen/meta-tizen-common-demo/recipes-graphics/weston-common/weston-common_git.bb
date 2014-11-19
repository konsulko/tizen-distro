require weston-common.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/common/weston-common;tag=0e6dd7341730320a5e5f93f6829b396c9a3bf779;nobranch=1"

BBCLASSEXTEND += " native "

