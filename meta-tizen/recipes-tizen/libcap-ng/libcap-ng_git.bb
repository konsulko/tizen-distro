require libcap-ng.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libcap-ng;protocol=ssh;tag=f78c1fda9fbc4dff23280b0f1c5be9b997340892;nobranch=1"

