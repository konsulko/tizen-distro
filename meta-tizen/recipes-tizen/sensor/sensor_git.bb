require sensor.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/system/libslp-sensor;tag=0b466302afcb0ce0e23f0d8f1e1e9820e42326dc;nobranch=1"

BBCLASSEXTEND += " native "

