require libmm-common.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/libmm-common;tag=b278ce78e1bdad66d46a051ec0258c13fbf85032;nobranch=1"

BBCLASSEXTEND += " native "

