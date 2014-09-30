require capi-system-system-settings.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/system-settings;tag=8789adea7dae840914101a770a25ed5ef04e3f73;nobranch=1"

BBCLASSEXTEND += " native "

