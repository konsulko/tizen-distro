require system-info.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/system-info;tag=4d1b9d0d38f512265b8c6126fbd2e7928bc08cf3;nobranch=1"

BBCLASSEXTEND += " native "

