require elementary.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/elementary;tag=b92b97d80f2bdc64be66c9b7d6c79a4cdd35e7bb;nobranch=1"

BBCLASSEXTEND += " native "

