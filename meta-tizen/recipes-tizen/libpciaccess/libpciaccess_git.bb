require libpciaccess.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libpciaccess;protocol=ssh;tag=f78fc31c86aed51312b49c901a547491e4e0986b;nobranch=1"

