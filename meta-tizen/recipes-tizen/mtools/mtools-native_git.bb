require mtools.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/mtools;protocol=ssh;tag=231af7f45a0d646d95ec5e4eddef9be25aee5ef9;nobranch=1"

