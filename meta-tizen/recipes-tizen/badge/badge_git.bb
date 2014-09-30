require badge.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/badge;tag=beb1dd6f05cbb53204aa044c169e75d1af9d19e7;nobranch=1"

BBCLASSEXTEND += " native "

