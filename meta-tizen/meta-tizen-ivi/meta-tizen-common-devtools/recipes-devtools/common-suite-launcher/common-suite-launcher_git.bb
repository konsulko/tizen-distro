require common-suite-launcher.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/test/tools/common-suite-launcher;tag=ccb687b94fcde71c55838b5ec37441fadca46103;nobranch=1"

BBCLASSEXTEND += " native "

