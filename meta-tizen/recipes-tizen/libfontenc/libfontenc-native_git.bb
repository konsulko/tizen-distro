require libfontenc.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libfontenc;protocol=ssh;tag=acbf8e04c66b765acd5f1a79fef457de7f7cbb0f;nobranch=1"

