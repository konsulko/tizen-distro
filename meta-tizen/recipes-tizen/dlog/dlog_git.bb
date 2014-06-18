require dlog.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/system/dlog;tag=a08e5247c86df41b8d68438b782095208751ae9c;nobranch=1"

BBCLASSEXTEND += " native "

