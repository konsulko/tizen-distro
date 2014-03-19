require connman.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/connman;protocol=ssh;tag=7a3541b4f5e6d21fa39385bc9c12cb0e3b377358;nobranch=1"

