require libmnl.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libmnl;protocol=ssh;tag=c40ac5e9c3588cf4d542cc04948cc9aff4068783;nobranch=1"

