require neardal.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/neardal;tag=87f41a7bd3b4bcc1bb3c54ffaeda53f5e65dc8a7;nobranch=1"

BBCLASSEXTEND += " native "

