require fontconfig.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/fontconfig;protocol=ssh;tag=19f646b562a7c2ea7fa5a90d7ec7768a2a81d986;nobranch=1"

