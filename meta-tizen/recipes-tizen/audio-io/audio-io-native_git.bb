require audio-io.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/audio-io;protocol=ssh;tag=b2f7af0f53e8386773883383be5e9fc0285b05a5;nobranch=1"

