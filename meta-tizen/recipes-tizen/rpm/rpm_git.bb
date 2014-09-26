require rpm.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/rpm;tag=6af979ffe246fcc3c5286893f364a4691094beca;nobranch=1"

BBCLASSEXTEND += " native "

