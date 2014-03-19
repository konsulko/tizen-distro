require keyutils.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/keyutils;protocol=ssh;tag=0a66e7614aa2dead8af0e490b1bec71d8b895749;nobranch=1"

