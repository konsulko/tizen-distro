require libmm-fileinfo.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/libmm-fileinfo;tag=22b63cf9358324558602ba5ccb374201f785812c;nobranch=1"

BBCLASSEXTEND += " native "

