require weston.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/weston;tag=3b2b540a6c211b599d7cf9ace0026572d9fc3ec9;nobranch=1"

BBCLASSEXTEND += " native "

