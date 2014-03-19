require libmm-session.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/libmm-session;protocol=ssh;tag=cfbc912e50461f204a2ba519ab40a84a45c03bf6;nobranch=1"

