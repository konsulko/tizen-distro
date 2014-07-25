require fdupes.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/fdupes;tag=796ff677d7ed1bdd2fb8d3b48572dba6a8e111f6;nobranch=1"

BBCLASSEXTEND += " native "

