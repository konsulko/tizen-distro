require alsa-scenario-0.2.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/alsa-scenario-0.2;protocol=ssh;tag=8a7abb902764c6afdd4c3fab4d0ac29716117207;nobranch=1"

