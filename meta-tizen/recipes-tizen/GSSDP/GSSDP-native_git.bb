require GSSDP.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/GSSDP;protocol=ssh;tag=6ecb02705ec583bfd92ff8ead4b85b56d0f1858f;nobranch=1"

