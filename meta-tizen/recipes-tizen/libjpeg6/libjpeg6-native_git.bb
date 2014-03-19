require libjpeg6.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libjpeg6;protocol=ssh;tag=c24fd1478fcb5dc13fda8400dbf50a52e009db94;nobranch=1"

