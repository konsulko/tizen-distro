require libtirpc.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libtirpc;protocol=ssh;tag=0aacafcef4cdbc7ebc3f266407052926ff40ee9e;nobranch=1"

