require pam.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/pam;tag=523d88f2bf88a131d6b4a334e85d2666d505dc48;nobranch=1"

BBCLASSEXTEND += " native "

