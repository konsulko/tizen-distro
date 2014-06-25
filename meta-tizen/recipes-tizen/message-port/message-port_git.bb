require message-port.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/message-port;tag=047b8655fc59cb24d8937d132455dd1e521a4d1f;nobranch=1"

BBCLASSEXTEND += " native "

