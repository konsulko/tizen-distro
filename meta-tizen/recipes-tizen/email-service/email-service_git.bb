require email-service.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/messaging/email-service;protocol=ssh;tag=7e2c216892ac4d1ae8b4ec838f61f6213099b6e8;nobranch=1"

