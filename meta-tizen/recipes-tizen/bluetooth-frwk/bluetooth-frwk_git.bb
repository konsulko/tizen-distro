require bluetooth-frwk.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/connectivity/bluetooth-frwk;tag=9319c8e659d1194a7682350468da6c8fc6cd58cb;nobranch=1"

BBCLASSEXTEND += " native "

