require adns.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/adns;tag=20e474eda39bdaa3ab7a80345e77d93967d55f88;nobranch=1"

BBCLASSEXTEND += " native "

