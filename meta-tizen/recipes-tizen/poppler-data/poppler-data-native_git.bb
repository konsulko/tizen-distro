require poppler-data.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/poppler-data;protocol=ssh;tag=6e197ca1c5434cb2b7956573f2c7798cdfd75ab1;nobranch=1"

