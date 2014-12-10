require media-server.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/media-server;tag=b1cba9bae69f8a13e85edfb3cf6f5e30948e8852;nobranch=1"

BBCLASSEXTEND += " native "

