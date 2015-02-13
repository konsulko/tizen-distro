require tiff.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/tiff;tag=a7123bacbef4cf6265a5bde3eb4e65af3962ce12;nobranch=1"

BBCLASSEXTEND += " native "

