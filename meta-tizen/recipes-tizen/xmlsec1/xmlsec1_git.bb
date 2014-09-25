require xmlsec1.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/xmlsec1;tag=839015fd0f40e78c6afc13daebb093a22d9d5d61;nobranch=1"

BBCLASSEXTEND += " native "

