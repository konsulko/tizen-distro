require media-server.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/media-server;tag=2951a46a90784516e1c9ef701b00c0e9b3ea3e9e;nobranch=1"

BBCLASSEXTEND += " native "

