require message-port.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/message-port;tag=288d95a39a51021a5260be6d879ddd56a8ac7b65;nobranch=1"

BBCLASSEXTEND += " native "

