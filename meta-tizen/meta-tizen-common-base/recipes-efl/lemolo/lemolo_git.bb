require lemolo.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/lemolo;tag=b04fcc0601b9b7d9e0bc1d90d23a4166ce3fa6a6;nobranch=1"

BBCLASSEXTEND += " native "

