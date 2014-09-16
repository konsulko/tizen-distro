require efl.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/efl;tag=78b3840c9c1d8915542145735414d75a2b349ec0;nobranch=1"

BBCLASSEXTEND += " native "

