require libxkbcommon.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libxkbcommon;protocol=ssh;tag=90fa6102f8deca66be5b0bf9fa0960cb81d7039e;nobranch=1"

