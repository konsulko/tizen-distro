require evolution-data-server.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/evolution-data-server;tag=f8f9a927b8170f19a668d9664ca0bf747368a8b4;nobranch=1"

BBCLASSEXTEND += " native "

