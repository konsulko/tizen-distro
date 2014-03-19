require tcpdump.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/tcpdump;protocol=ssh;tag=09a0a046c9c1bd6df1834f4f4804753bd0788785;nobranch=1"

