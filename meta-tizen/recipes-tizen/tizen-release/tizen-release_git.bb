require tizen-release.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/tizen-release;protocol=ssh;tag=92f879a70cc15569ae67d50190853e213f90066e;nobranch=1"

