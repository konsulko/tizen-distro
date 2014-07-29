require libwebsockets.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/libwebsockets;tag=270620a55c0144f0af05f006523f2d294298ade2;nobranch=1"

BBCLASSEXTEND += " native "

