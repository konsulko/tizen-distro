require evolution-data-server.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/evolution-data-server;tag=478626e83843b8a5c93eccd8e3dd5241805b0244;nobranch=1"

BBCLASSEXTEND += " native "

