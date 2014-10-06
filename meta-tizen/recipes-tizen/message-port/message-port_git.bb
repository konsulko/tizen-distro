require message-port.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/message-port-dbus;tag=a32937b52205b0878b9f20f01ed2cee73c2cd53a;nobranch=1"

BBCLASSEXTEND += " native "

