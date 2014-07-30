require libsvi.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/system/libsvi;tag=cd42f792953e7add4f9f9724c1101de89ec05f3c;nobranch=1"

BBCLASSEXTEND += " native "

