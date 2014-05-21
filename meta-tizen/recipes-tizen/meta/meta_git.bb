require meta.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/common/meta;tag=ff5e0c3793c1f59857013a0f4693a6662a30ea9d;nobranch=1"

BBCLASSEXTEND += " native "

