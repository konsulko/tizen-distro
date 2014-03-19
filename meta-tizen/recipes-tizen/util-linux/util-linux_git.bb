require util-linux.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/util-linux;protocol=ssh;tag=8d9c9a341157cc8b0dba1c6781dde22e6f7a2fcf;nobranch=1"

