require bluetooth-share.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/connectivity/bluetooth-share;protocol=ssh;tag=507bbf3c5ee50770b6c4994a20e20e8f34510f7e;nobranch=1"

