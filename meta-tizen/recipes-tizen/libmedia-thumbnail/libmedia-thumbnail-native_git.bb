require libmedia-thumbnail.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/libmedia-thumbnail;protocol=ssh;tag=5501705ca2088e4fea1d5387b252a61cacfd530b;nobranch=1"

