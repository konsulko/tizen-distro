require xdg-utils.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/xdg-utils;protocol=ssh;tag=d7ead885ed669476df6a16e5c024de279bbc16f0;nobranch=1"

