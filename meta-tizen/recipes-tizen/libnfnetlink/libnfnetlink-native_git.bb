require libnfnetlink.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libnfnetlink;protocol=ssh;tag=799f84b01c26970d8a72b058661515a9441ce316;nobranch=1"

