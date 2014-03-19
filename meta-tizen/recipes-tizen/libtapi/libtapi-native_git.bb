require libtapi.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/telephony/libtapi;protocol=ssh;tag=fd171c7de7ea0766ad7c2091a3621c0b5a90ede9;nobranch=1"

