require libnl1.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libnl1;protocol=ssh;tag=6b652653f015359a28b8c21c34747638925f44ae;nobranch=1"

