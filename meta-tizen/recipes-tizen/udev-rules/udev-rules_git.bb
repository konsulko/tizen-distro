require udev-rules.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/udev-rules;tag=f4c1dc2f26f647eeb790b6df1868da7bd1548eb2;nobranch=1"

BBCLASSEXTEND += " native "

