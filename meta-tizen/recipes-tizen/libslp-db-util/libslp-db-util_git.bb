require libslp-db-util.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/libslp-db-util;tag=4ef37c0712f5f5043768c66ffef2a7f5b76ba940;nobranch=1"

BBCLASSEXTEND += " native "

