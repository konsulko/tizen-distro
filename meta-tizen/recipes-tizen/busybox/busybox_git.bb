require busybox.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/busybox;protocol=ssh;tag=571c63fc8ee16cf8cfde11e78ac6f8ec961c9dba;nobranch=1"

