require sqlite.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/sqlite;protocol=ssh;tag=6d3eef95de5a510d5b5d1ab49db7ed5dc806d6e6;nobranch=1"

