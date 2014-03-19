require pc-installer.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/pc-installer;protocol=ssh;tag=2e5cf8d04740ef39c21beab2b4ea5a2d332a320b;nobranch=1"

