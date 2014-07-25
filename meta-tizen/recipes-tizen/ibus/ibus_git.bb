require ibus.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/ibus;tag=87fae7bdb68169124c816704ad91ccc94ab7b1d4;nobranch=1"

BBCLASSEXTEND += " native "

