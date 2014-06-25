require libmm-utility.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/libmm-utility;tag=bd9a7e1a59dbee5b8ac911b9ebb7017d13a8112f;nobranch=1"

BBCLASSEXTEND += " native "

