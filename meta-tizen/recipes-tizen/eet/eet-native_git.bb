require eet.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/eet;protocol=ssh;tag=4dc68af514f8a8cc9fb4d5c1b32e14731aeb1ce8;nobranch=1"

