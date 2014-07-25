require pam.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/pam;tag=a67b6f8ae9bd2628dfa9e6162781216b41e56131;nobranch=1"

BBCLASSEXTEND += " native "

