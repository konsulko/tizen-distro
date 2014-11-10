require bullet.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libbullet;tag=03875b02d03ae029f38cb35dc90ee3ff6d5fe696;nobranch=1"

BBCLASSEXTEND += " native "

