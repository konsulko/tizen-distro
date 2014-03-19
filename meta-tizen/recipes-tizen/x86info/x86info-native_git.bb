require x86info.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/x86info;protocol=ssh;tag=2b7b22999f433387a24b0eef20c9fcb7d02b98d0;nobranch=1"

