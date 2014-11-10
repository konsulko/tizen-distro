require libxml2.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libxml2;tag=e52e7cd8d3553116787eb0573f3b3d379f09698a;nobranch=1"

BBCLASSEXTEND += " native "

