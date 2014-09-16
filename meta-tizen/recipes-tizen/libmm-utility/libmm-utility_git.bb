require libmm-utility.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/libmm-utility;tag=ca7b89f7f083c83383236e80d9121d6b27f3a5d1;nobranch=1"

BBCLASSEXTEND += " native "

