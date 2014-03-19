require yum.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/yum;protocol=ssh;tag=40014cdf8aae2f0a8c3eccd7f908e6ed1f5ddd65;nobranch=1"

