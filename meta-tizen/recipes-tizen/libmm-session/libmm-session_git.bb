require libmm-session.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/libmm-session;tag=41cd8d8afa6d774db20a904c2f4ea44e3b278555;nobranch=1"

BBCLASSEXTEND += " native "

