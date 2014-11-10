require libmm-session.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/libmm-session;tag=7976f6b9ab618982fe475f5ed0d96a9f5ade20d9;nobranch=1"

BBCLASSEXTEND += " native "

