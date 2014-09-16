require aul-1.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/aul-1;tag=256ec13cd6cccf17cce98b1bb0caadf15d75d0cf;nobranch=1"

BBCLASSEXTEND += " native "

