require ico-uxf-device-input-controller.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/ico-uxf-device-input-controller;tag=6554394e29dc2c8409726a096beef43083f28145;nobranch=1"

BBCLASSEXTEND += " native "

