require system-info.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/system-info;tag=53ef242e5153d199d6e73cc4e82d883e79aa1a70;nobranch=1"

BBCLASSEXTEND += " native "

