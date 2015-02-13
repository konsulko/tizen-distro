require cynara.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/security/cynara;tag=6c079ffeed2e4dc0c8cec00e5a7da67f3c5e2564;nobranch=1"

BBCLASSEXTEND += " native "

