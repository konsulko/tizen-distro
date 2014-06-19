require smack.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/smack;tag=fb9a8e1c235834357a57ecd47cc45ba12805ad6d;nobranch=1"

BBCLASSEXTEND += " native "

