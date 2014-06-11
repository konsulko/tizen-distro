require librua.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/librua;tag=b3f0019b1e8c118e7f96248d143f43a02c05a4e7;nobranch=1"

BBCLASSEXTEND += " native "

