require ofono.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/ofono;tag=02f89fd9a48fccc1702de9cc8f5c76cb72f54bc2;nobranch=1"

BBCLASSEXTEND += " native "

