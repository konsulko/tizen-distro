require ibus-hangul.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/ibus-hangul;tag=50ba9a0088d93b9a426f29d19e6eb63e556ca155;nobranch=1"

BBCLASSEXTEND += " native "

