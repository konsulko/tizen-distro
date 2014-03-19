require libmm-radio.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/libmm-radio;protocol=ssh;tag=d75abc84503d38da38685501dd449090cde1c3e9;nobranch=1"

