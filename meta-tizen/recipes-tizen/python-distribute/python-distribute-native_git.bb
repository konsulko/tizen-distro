require python-distribute.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/python-distribute;protocol=ssh;tag=731bc0e2f68b1dda409a5f3a1f1499fb13fdb22c;nobranch=1"

