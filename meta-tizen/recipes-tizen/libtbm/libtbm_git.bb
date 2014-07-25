require libtbm.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/uifw/libtbm;tag=ae239898e9e011b8893c739e850c3ba3f1b76815;nobranch=1"

BBCLASSEXTEND += " native "

