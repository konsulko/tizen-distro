require chromium.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/chromium;protocol=ssh;tag=3f7c0903daea1bba8d6f817ac077fe4ef8a238fb;nobranch=1"

