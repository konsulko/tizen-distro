require capi-media-image-util.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/image-util;tag=f02004b94ca2b2c0c21c67be0a0d1ce8edee0a75;nobranch=1"

BBCLASSEXTEND += " native "

