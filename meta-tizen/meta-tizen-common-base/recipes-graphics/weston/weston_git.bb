require weston.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/weston;tag=1a5eb4a432485c9c78b937f45115da36979921cf;nobranch=1"

BBCLASSEXTEND += " native "

