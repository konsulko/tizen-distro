require ibus-libpinyin.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/ibus-libpinyin;tag=d0248b5f265cdf73a06754ef0384a8708cbc8c02;nobranch=1"

BBCLASSEXTEND += " native "

