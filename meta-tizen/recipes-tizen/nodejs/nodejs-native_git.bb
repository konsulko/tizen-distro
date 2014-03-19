require nodejs.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/nodejs;protocol=ssh;tag=ae108fbf071489b3635f7c9e612bfc2577051576;nobranch=1"

