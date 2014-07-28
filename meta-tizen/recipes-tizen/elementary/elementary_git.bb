require elementary.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/elementary;tag=4400d8696a68fa665b89ed1ce29ab3c39c6ed3ac;nobranch=1"

BBCLASSEXTEND += " native "

