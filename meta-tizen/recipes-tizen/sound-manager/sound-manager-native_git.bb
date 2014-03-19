require sound-manager.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/sound-manager;protocol=ssh;tag=cf15d56b4f8a8255cb5861cc0228c2c3172d7ca0;nobranch=1"

