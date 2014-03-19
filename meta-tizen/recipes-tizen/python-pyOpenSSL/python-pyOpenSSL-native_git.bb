require python-pyOpenSSL.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/python-pyOpenSSL;protocol=ssh;tag=86127911c0159224e4d58325c9dc25a59bb91f5e;nobranch=1"

