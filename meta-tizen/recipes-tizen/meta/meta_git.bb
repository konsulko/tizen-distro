require meta.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/common/meta;tag=213b8e680631bd284f50c1eb7ca3b2a3243ca255;nobranch=1"

BBCLASSEXTEND += " native "

