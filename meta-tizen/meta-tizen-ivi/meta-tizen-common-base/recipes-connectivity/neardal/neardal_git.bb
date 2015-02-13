require neardal.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/neardal;tag=c8241fc5a9e27aa1c53ea6980618c00e4c74a2c4;nobranch=1"

BBCLASSEXTEND += " native "

