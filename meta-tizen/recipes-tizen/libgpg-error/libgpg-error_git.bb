require libgpg-error.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libgpg-error;protocol=ssh;tag=3f2c55d70c10885af673d45e2acc85445578978a;nobranch=1"

