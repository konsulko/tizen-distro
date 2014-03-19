require openal-soft.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/openal-soft;protocol=ssh;tag=3d48b01fa5a83dc4e861130af44255af71a14466;nobranch=1"

