require libjpeg-turbo.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libjpeg-turbo;protocol=ssh;tag=92e0ae092a0cb7d193d58e7f2904571669214dc5;nobranch=1"

