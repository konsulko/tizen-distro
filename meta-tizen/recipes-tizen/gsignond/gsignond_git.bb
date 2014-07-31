require gsignond.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/gsignond;tag=3b020093ac6bcc6ef4ccd8a9ecd6286f136f26d6;nobranch=1"

BBCLASSEXTEND += " native "

