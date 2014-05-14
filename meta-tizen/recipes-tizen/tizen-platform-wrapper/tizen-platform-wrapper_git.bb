require tizen-platform-wrapper.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/tizen-platform-wrapper;tag=e6cc0052b4904f715bd57014ce21e77405f8d3a9;nobranch=1"

BBCLASSEXTEND = "native"

