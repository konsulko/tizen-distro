require glib-networking.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/glib-networking;protocol=ssh;tag=ca71a38a3b0282467302eab653d92fa4f49e94e1;nobranch=1"

