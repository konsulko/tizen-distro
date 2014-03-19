require iso-ent.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/iso_ent;protocol=ssh;tag=40109c53959c87ebd0d1be7859080468e655c204;nobranch=1"

