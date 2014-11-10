require keyutils.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/keyutils;tag=5ecf742b33f27aee297ab68f74704b2ee52bceb6;nobranch=1"

BBCLASSEXTEND += " native "

