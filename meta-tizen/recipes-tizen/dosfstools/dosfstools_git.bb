require dosfstools.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/dosfstools;protocol=ssh;tag=b156136ea7bd8d6e7a16d89cd6680d8223945679;nobranch=1"

