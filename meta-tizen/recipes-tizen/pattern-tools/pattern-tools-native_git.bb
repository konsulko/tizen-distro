require pattern-tools.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/pattern-tools;protocol=ssh;tag=c5daa3aaf170968d9e8d436998a0a13dfd7f0c15;nobranch=1"

