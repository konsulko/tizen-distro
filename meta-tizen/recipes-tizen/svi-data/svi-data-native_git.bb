require svi-data.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/system/svi-data;protocol=ssh;tag=0e8d5870fa7f8ff2b91c20e31b6d370389f4eef8;nobranch=1"

