require meta.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/common/meta;tag=1a07b29fa9a16e231abdd02a46bc56c928c8fd3c;nobranch=1"

BBCLASSEXTEND += " native "

