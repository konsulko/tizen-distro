require fsync.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/fsync;protocol=ssh;tag=5e0c503d103760edc57f83f3f1e88c60a075bb2e;nobranch=1"

