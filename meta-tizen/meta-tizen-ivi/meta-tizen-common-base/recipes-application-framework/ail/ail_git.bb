require ail.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/ail;tag=139abb1c6feadabb95cd3e4a752c7833d8a3d468;nobranch=1"

BBCLASSEXTEND += " native "

