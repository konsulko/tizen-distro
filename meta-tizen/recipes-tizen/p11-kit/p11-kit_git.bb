require p11-kit.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/p11-kit;protocol=ssh;tag=be63827d2b3b23e2635892f42de820524e44e252;nobranch=1"

