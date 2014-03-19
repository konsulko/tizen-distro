require net-tools.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/net-tools;protocol=ssh;tag=1bfd01a3262139d0c41c5d2c3c5fef5af004aa2f;nobranch=1"

