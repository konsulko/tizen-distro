require python-coverage.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/python-coverage;protocol=ssh;tag=1d72c85817e97ac13ac619add1b83a95b08d9c93;nobranch=1"

