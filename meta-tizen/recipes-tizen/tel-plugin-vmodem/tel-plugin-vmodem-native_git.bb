require tel-plugin-vmodem.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/telephony/tel-plugin-vmodem;protocol=ssh;tag=b6fc4f071edfa63f1bcb6f89115a61eed95be62f;nobranch=1"

