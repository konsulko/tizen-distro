require capi-base-common.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/common;tag=09b56a10f65dd1869c2d1ea987190fa9d9cafd69;nobranch=1"

BBCLASSEXTEND += " native "

