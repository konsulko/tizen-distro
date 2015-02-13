require notification.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/notification;tag=6d3c4efa9d5285bb6fb9eef61a32ee5ce2c3b632;nobranch=1"

BBCLASSEXTEND += " native "

