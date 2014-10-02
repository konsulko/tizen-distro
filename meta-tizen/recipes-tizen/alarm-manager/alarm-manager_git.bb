require alarm-manager.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/alarm-manager;tag=b8807e9c4192e960c4abe2002cbde3e8d280fad4;nobranch=1"

BBCLASSEXTEND += " native "

