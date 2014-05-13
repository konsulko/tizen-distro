require tizen-platform-config.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/tizen-platform-config;tag=975455172dd3acb0022992e09c1a9fffd41a5e45;nobranch=1"

BBCLASSEXTEND = "native"

