require libdaemon.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libdaemon;protocol=ssh;tag=7bc845d5036f91acbf65ce5c1f57974295cf22b4;nobranch=1"

