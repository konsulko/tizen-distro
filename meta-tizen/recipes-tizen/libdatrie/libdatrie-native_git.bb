require libdatrie.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libdatrie;protocol=ssh;tag=4abf32a6e72e18fc6e9cf459825ff39cd5b29305;nobranch=1"

