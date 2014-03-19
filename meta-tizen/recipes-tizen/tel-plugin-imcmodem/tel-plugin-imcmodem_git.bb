require tel-plugin-imcmodem.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/telephony/tel-plugin-imcmodem;protocol=ssh;tag=cf32059c14c8b8cd6ec4fce474ceedbcb9cd1d62;nobranch=1"

