require hwdata.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/hwdata;tag=ece4331ca9f60d359ed0270ba59fcb2b3dce6396;nobranch=1"

BBCLASSEXTEND += " native "

