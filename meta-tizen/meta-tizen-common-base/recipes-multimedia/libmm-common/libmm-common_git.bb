require libmm-common.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/libmm-common;tag=f5de4864de134462423a88fa214bb6a91a6c5bb3;nobranch=1"

BBCLASSEXTEND += " native "

