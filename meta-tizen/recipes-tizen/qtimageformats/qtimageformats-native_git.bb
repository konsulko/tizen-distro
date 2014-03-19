require qtimageformats.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/qtimageformats;protocol=ssh;tag=dd9e61a4e1e195a50aaf0b885f3f14eb27730131;nobranch=1"

