require libdrm.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libdrm;protocol=ssh;tag=95be3fff22e2d6083a36d0eb1c5a6bd0d685d408;nobranch=1"

