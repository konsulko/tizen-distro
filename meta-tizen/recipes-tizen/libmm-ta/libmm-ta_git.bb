require libmm-ta.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/libmm-ta;tag=bcf31b1706fa01175709015adfef70332df68496;nobranch=1"

BBCLASSEXTEND = "native"

