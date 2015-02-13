require capi-appfw-application.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/application;tag=4383609dbe3f4b43240030d392bb1b81aef22b0f;nobranch=1"

BBCLASSEXTEND += " native "

