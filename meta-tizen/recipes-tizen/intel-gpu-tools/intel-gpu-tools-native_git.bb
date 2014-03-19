require intel-gpu-tools.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/extras/intel-gpu-tools;protocol=ssh;tag=3c7b03f2f7b4ecfb18fb30f2e43b6321cb1aa4de;nobranch=1"

