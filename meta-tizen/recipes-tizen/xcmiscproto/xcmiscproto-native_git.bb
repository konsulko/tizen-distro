require xcmiscproto.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/xcmiscproto;protocol=ssh;tag=b2454d86879a9a789dcbec7e6d1bc46070373186;nobranch=1"

