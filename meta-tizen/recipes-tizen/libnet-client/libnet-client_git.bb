require libnet-client.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/connectivity/libnet-client;tag=40fca8c3bf88877ec93c7e191064f94ca68c365c;nobranch=1"

BBCLASSEXTEND += " native "

