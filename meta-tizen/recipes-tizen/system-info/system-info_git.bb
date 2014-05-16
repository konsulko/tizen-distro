require system-info.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/system-info;tag=09a0f990e9ee12b29ea256dd34c8f0380e0b47ea;nobranch=1"

BBCLASSEXTEND += " native "

