require msg-service.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/messaging/msg-service;tag=da44d306ea4f55e6a7b75c96783bb7c61cd75c8a;nobranch=1"

BBCLASSEXTEND += " native "

