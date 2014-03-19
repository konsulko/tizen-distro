require python-M2Crypto.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/python-M2Crypto;protocol=ssh;tag=60dc7fafc560768347b6c9bae9f79ff4b3901240;nobranch=1"

