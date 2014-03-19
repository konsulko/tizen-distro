require tolua++.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/tolua++;protocol=ssh;tag=4116ac1492c7779d04e7f121f929783b93ad6725;nobranch=1"

