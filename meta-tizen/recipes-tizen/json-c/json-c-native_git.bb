require json-c.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/json-c;protocol=ssh;tag=c76aaf4b022ce447dfe1cc6424141dd9cd2d9c17;nobranch=1"

