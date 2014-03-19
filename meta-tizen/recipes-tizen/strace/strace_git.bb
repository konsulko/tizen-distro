require strace.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/strace;protocol=ssh;tag=108f793d4ab176f6e0242803360790f988cf6622;nobranch=1"

