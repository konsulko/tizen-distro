require vim.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/vim;protocol=ssh;tag=1149cc7a3c7ba6bc92c28bf200495f938d3eca8a;nobranch=1"

