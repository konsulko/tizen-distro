require libtapi.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/telephony/libtapi-legacy;tag=8b002849deb1ec476e2bb6ab3cafd9a328253dce;nobranch=1"

BBCLASSEXTEND += " native "

