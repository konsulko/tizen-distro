require python-sqlite.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/python-sqlite;protocol=ssh;tag=1790f105a2c4130762e24f87060aaf1a78e22616;nobranch=1"

