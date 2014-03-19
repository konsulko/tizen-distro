require qtsensors.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/qtsensors;protocol=ssh;tag=d9c9cd35473de4a5989ed93e6a26bd2a90ecafef;nobranch=1"

