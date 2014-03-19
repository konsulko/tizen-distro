require zeromq.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/zeromq;protocol=ssh;tag=1d26b6e152a399955145f28d4a6171c8cf5baf9d;nobranch=1"

