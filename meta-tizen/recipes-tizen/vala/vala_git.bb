require vala.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/vala;tag=b9dc5bc4a4d841a362bd3252ecac6a927f42ecd5;nobranch=1"

BBCLASSEXTEND += " native "

