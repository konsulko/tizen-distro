require rpmlint-mini.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/rpmlint-mini;protocol=ssh;tag=811427acbd1eea9ee2031905e97d35e7c3461320;nobranch=1"

