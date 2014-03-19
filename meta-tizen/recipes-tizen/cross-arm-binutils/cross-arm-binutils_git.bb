require cross-arm-binutils.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/binutils;protocol=ssh;tag=24337f2949b6a4ad07a06de6305fe56fd5965c3d;nobranch=1"

