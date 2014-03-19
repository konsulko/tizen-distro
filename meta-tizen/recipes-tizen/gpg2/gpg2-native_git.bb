require gpg2.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/gpg2;protocol=ssh;tag=0d5860e8035a1c2577ffa72a5a004e48471d27a2;nobranch=1"

