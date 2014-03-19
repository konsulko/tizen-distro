require xorg-cf-files.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/xorg-cf-files;protocol=ssh;tag=a9fdd8632fe38d7db245e2505dc2adf7170395cd;nobranch=1"

