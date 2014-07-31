require libpinyin.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libpinyin;tag=cbfd53b7ca66dbcee55abdb0af9ee4d9446e5bde;nobranch=1"

BBCLASSEXTEND += " native "

