require libaio.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libaio;protocol=ssh;tag=1e88bacb553998d2c3cc95e6916a55cb88c3ff56;nobranch=1"

