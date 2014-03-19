require embryo.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/embryo;protocol=ssh;tag=ad9729e9dd342aec310c6a00c79a25bc86ccb4d0;nobranch=1"

