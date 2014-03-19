require bluez.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/bluez;protocol=ssh;tag=4c6a68e2541010817b12e42437f4831bdbf9ae5b;nobranch=1"

