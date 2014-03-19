require sudo.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/sudo;protocol=ssh;tag=3e43b0d7ac6ee32fc3e0cad4a2c3bc5b21ee0347;nobranch=1"

