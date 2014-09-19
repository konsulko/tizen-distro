require system-server.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/system/system-server;tag=458698a096ec94b8e6849179d8438d0e0b2a5503;nobranch=1"

BBCLASSEXTEND += " native "

