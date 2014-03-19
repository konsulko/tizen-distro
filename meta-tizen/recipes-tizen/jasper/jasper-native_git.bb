require jasper.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/jasper;protocol=ssh;tag=59b126c0d3c1e35645a26e686d4d61a9c8987b2f;nobranch=1"

