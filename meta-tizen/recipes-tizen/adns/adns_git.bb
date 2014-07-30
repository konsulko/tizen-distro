require adns.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/adns;tag=b17c61b0cea0a7b65f33a8454c0a017b5f95124c;nobranch=1"

BBCLASSEXTEND += " native "

