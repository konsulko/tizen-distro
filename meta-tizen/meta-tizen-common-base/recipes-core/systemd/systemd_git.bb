require systemd.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/systemd;tag=c9f3992581011a5dde3b1b03819bedb3d2579076;nobranch=1"

BBCLASSEXTEND += " native "

