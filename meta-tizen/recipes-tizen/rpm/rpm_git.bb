require rpm.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/rpm;protocol=ssh;tag=900e279b9481a75ede028707fe5a0a2bb2801a8f;nobranch=1"

