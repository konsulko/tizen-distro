require msg-service.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/messaging/msg-service;tag=76dc39ae7d9f91c3e489cff13bf701c79df87b27;nobranch=1"

BBCLASSEXTEND += " native "

