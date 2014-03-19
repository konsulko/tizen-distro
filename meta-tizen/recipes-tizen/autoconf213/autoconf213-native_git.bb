require autoconf213.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/autoconf213;protocol=ssh;tag=21db2b3894d31911828c934bb115eeb585c2b1bd;nobranch=1"

