require libsf-common.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/system/libsf-common;tag=d2dbdc7e801b265a71faf8a2f027d79e72b92424;nobranch=1"

BBCLASSEXTEND += " native "

