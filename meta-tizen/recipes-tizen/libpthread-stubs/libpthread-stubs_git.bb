require libpthread-stubs.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libpthread-stubs;protocol=ssh;tag=17bfd695c9e8a1005f08089fc9f8f3583f5962a4;nobranch=1"

