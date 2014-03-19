require eldbus.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/eldbus;protocol=ssh;tag=c67026808d3ab28c85b93306122f623de07dcb7f;nobranch=1"

