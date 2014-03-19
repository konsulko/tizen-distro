require emotion.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/emotion;protocol=ssh;tag=6cd996cd2bfaddc03253285a742d94ec14a2c300;nobranch=1"

