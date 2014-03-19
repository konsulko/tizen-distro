require python-cairo.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/python-cairo;protocol=ssh;tag=57fd7f1e0f60e7e685c4abae1200f75561973d67;nobranch=1"

