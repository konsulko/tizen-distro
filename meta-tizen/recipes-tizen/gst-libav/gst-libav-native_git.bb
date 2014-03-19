require gst-libav.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/gst-libav;protocol=ssh;tag=59b24acf50350f49fea6354aa5b445d70c3d8253;nobranch=1"

