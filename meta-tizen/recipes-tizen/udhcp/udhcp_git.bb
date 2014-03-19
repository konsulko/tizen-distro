require udhcp.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/udhcp;protocol=ssh;tag=390a4f7e04940db3ce50b0887fe6ce22e864f4c1;nobranch=1"

