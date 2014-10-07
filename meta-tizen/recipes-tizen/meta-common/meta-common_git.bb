require meta-common.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/common/meta;tag=ebbc2b97e4bfb99afbab1ec7741c835e4f9161b7;nobranch=1"

BBCLASSEXTEND += " native "

