require tel-plugin-atmodem.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/telephony/tel-plugin-atmodem;protocol=ssh;tag=6139aa8b651ee716a0cec0ddaf951be09367b6a4;nobranch=1"

