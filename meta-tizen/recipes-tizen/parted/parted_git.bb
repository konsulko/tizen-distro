require parted.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/parted;protocol=ssh;tag=c55a46ef685aebb1c11aae738d515b9ba5a68016;nobranch=1"

