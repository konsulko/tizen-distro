require desktop-file-utils.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/desktop-file-utils;tag=bfa7b3071761f5bc410d7530b2d18f7883b06490;nobranch=1"

BBCLASSEXTEND += " native "

