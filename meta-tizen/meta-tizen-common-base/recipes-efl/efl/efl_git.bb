require efl.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/efl;tag=f7a97238b515310da98621328aadb9275bc92012;nobranch=1"

BBCLASSEXTEND += " native "

