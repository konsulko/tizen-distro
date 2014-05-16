require common.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/common;tag=708dfdeef6668d6a0e7a608be1f82619f3b38393;nobranch=1"

BBCLASSEXTEND += " native "

