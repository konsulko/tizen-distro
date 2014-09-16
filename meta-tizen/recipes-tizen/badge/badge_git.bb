require badge.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/badge;tag=63663b8d2ba6f0b13121bbf3ba40ecea7f42744b;nobranch=1"

BBCLASSEXTEND += " native "

