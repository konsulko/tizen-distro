require heynoti.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/heynoti;tag=3f82d6115368fb5a2d799436aecc7b339e6ae373;nobranch=1"

BBCLASSEXTEND += " native "

