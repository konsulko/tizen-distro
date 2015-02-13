require libtapi3.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/telephony/libtapi;tag=16c6314e7e71542ee8bb3f51cc22259e57d27837;nobranch=1"

BBCLASSEXTEND += " native "

