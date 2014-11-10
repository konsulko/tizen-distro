require libav.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libav;tag=0fd9bbab02cc36060782e7a1f68417b5810300bf;nobranch=1"

BBCLASSEXTEND += " native "

