require smack.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/smack;tag=aab09845e6c314b621a9f3756dd2504c2498d569;nobranch=1"

BBCLASSEXTEND += " native "

