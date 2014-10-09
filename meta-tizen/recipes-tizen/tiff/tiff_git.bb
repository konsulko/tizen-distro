require tiff.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/tiff;tag=2d1548a92a4768584c545d5c40fa203883612eb0;nobranch=1"

BBCLASSEXTEND += " native "

