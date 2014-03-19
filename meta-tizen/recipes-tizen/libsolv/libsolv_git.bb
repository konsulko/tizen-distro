require libsolv.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libsolv;protocol=ssh;tag=9092da2d875f5c060ea6834dac84392a43a7eba4;nobranch=1"

