require libmm-common.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/libmm-common;tag=8e74a5450dab4e987c2864e469597f26333ca63d;nobranch=1"

BBCLASSEXTEND += " native "

