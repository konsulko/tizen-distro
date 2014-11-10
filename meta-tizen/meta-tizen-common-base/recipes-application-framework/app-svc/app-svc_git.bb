require app-svc.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/app-svc;tag=20a5461703eabca371b655ec968ed0175e06ea25;nobranch=1"

BBCLASSEXTEND += " native "

