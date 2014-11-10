require udev-rules.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/udev-rules;tag=b4fa71b1f6422ebf2618d2b73a5c6eb288a09397;nobranch=1"

BBCLASSEXTEND += " native "

