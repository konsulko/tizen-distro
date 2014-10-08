require libav.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libav;tag=1445e92f0200ac2ce1a3988334a7d7992122f0f3;nobranch=1"

BBCLASSEXTEND += " native "

