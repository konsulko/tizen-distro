require gst-plugins-ugly.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/gst-plugins-ugly;protocol=ssh;tag=2844c1aeb429bad9d1c29d48402892bcd692d499;nobranch=1"

