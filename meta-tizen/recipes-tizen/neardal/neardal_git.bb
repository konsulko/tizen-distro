require neardal.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/neardal;tag=3bbe63f6b9e3e49816d7d65fa95fdef6ac5dbe28;nobranch=1"

BBCLASSEXTEND += " native "

