require gst-plugins-bad.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/gst-plugins-bad;protocol=ssh;tag=9b3984d43c1d3b6ba3dc07cd2f651c08900be690;nobranch=1"

