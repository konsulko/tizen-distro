require meta-common.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/common/meta;tag=1071c301c12500e7aae7b459a61e8fce1e855ff4;nobranch=1"

BBCLASSEXTEND += " native "

