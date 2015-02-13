require iniparser.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/iniparser;tag=42358b2425b18976b324e773bd780342f6f57fcd;nobranch=1"

BBCLASSEXTEND += " native "

