require system-server.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/system/system-server;tag=c63f1ea1a039aa5efabab0d427426a92a0e343b4;nobranch=1"

BBCLASSEXTEND += " native "

