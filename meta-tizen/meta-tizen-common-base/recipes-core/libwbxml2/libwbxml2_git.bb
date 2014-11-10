require libwbxml2.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libwbxml2;tag=717cf1e3430cacd4c0ba04394b8f60f1e4ad4900;nobranch=1"

BBCLASSEXTEND += " native "

