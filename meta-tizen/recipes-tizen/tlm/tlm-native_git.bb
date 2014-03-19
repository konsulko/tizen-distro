require tlm.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/system/tlm;protocol=ssh;tag=88ab62b0d7845a57536306c88df2c037b04d7bc3;nobranch=1"

