require wireless-regdb.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/wireless-regdb;protocol=ssh;tag=4538f798db50c9abe049390406d8ac2cbc00dd01;nobranch=1"

