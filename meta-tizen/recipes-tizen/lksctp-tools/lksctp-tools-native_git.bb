require lksctp-tools.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/lksctp-tools;protocol=ssh;tag=62b3a14012cc6ea28421a98152e8c21b98a899d9;nobranch=1"

