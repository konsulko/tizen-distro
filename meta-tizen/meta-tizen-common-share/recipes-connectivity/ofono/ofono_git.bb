require ofono.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/ofono;tag=f611670427a989b25a60dcfe0940efa424849931;nobranch=1"

BBCLASSEXTEND += " native "

