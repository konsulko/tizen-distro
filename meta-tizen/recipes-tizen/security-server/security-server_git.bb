require security-server.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/security/security-server;tag=ddc0b44b013c92a78f43ddf060a0d7a02a88c591;nobranch=1"

BBCLASSEXTEND += " native "

