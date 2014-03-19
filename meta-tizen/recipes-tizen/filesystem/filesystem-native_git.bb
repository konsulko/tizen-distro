require filesystem.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/filesystem;protocol=ssh;tag=4b4d6ad94e7560fd21adfa8fe27173fa8efd1c0d;nobranch=1"

