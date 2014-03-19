require dos2unix.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/dos2unix;protocol=ssh;tag=0a42b2c1aaae30f4d7be437485364853cb0b30c9;nobranch=1"

