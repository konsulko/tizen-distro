require libtbm.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/uifw/libtbm;tag=e139de0af17fcee35838afbc6947bd9f7b9c6042;nobranch=1"

BBCLASSEXTEND += " native "

