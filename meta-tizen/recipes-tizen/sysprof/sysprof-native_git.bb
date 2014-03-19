require sysprof.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/sysprof;protocol=ssh;tag=510029309bfa269fa9d58ebb7e3e93b7d1b2b432;nobranch=1"

