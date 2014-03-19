require alsa-plugins.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/alsa-plugins;protocol=ssh;tag=19c484e9bc0d77034e4871a1c36752b9b5ed1a92;nobranch=1"

