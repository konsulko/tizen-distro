require syslinux.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/syslinux;protocol=ssh;tag=588e83546aa3143d129c308726370e13f0405049;nobranch=1"

