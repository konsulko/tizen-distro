require libav.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libav;tag=8e5fcbeb90f32dd1120b12b652095568f60b9575;nobranch=1"

BBCLASSEXTEND += " native "

