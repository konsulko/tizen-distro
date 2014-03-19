require linux-firmware.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/linux-firmware;protocol=ssh;tag=495bc902da2000baf67b0cc6af9906f3b7b6de84;nobranch=1"

