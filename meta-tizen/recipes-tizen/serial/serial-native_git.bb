require serial.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/serial;protocol=ssh;tag=5d5a6639ace5cfbc1a7abff102e5018c9cf8acb6;nobranch=1"

