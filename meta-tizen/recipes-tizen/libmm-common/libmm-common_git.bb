require libmm-common.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/libmm-common;tag=507959cbf4f293fb3477d4900e2d4b37b0d9f096;nobranch=1"

BBCLASSEXTEND += " native "

