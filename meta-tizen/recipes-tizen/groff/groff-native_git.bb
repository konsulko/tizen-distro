require groff.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/groff;protocol=ssh;tag=cc8f01dac8fe7d0228f912ccb7f44ced0cc2990f;nobranch=1"

