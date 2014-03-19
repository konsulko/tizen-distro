require calculator.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/apps/core/preloaded/calculator;protocol=ssh;tag=22fb7dbbe278fa7ed4b31fdd8b34c785848e7ead;nobranch=1"

