require bzip2.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/bzip2;protocol=ssh;tag=2eaa43958f0416d06758a05fe93d098002ee339d;nobranch=1"

