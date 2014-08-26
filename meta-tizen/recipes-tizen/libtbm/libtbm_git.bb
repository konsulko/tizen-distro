require libtbm.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/uifw/libtbm;tag=2ebf5095f20bfbe63a2c9e8cf79c804612dae110;nobranch=1"

BBCLASSEXTEND += " native "

