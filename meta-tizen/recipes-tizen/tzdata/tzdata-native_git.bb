require tzdata.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/tzdata;protocol=ssh;tag=1dbf7b3964adde0a77bfe6503869d33655425e8e;nobranch=1"

