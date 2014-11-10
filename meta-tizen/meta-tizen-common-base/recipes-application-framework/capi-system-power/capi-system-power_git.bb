require capi-system-power.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/power;tag=39f484023de4f5a4dbf25718c8d30c0821810c18;nobranch=1"

BBCLASSEXTEND += " native "

