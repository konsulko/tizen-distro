require libICE.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libICE;tag=754a5288034a779667c0f8216a3b1402a20bff54;nobranch=1"

BBCLASSEXTEND += " native "

