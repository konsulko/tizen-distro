require libmm-utility.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/libmm-utility;tag=4295b93e417e4734c90639d20ff6c60b110172d7;nobranch=1"

BBCLASSEXTEND += " native "

