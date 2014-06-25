require message-port.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/message-port;tag=4ee5f77116ba97e8588a7c4c329ee427e9147068;nobranch=1"

BBCLASSEXTEND += " native "

