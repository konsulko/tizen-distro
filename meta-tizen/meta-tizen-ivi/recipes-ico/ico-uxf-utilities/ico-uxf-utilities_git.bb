require ico-uxf-utilities.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/ico-uxf-utilities;tag=e5749682aabdd8cbe57045c52c37f72b01946b0f;nobranch=1"

BBCLASSEXTEND += " native "

