require ibus-libpinyin.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/ibus-libpinyin;tag=688886f093b5f0c7df174b8734b8b2dc43cc4815;nobranch=1"

BBCLASSEXTEND += " native "

