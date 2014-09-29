require ibus.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/ibus;tag=d474a5c218f8630192ee2bea8d321c245e2c2b89;nobranch=1"

BBCLASSEXTEND += " native "

