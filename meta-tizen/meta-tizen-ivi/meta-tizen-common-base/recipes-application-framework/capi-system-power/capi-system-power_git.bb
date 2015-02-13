require capi-system-power.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/power;tag=197d785da82c234517e30af1a1bcc1e517028762;nobranch=1"

BBCLASSEXTEND += " native "

