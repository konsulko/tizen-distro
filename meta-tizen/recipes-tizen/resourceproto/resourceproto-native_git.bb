require resourceproto.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/resourceproto;protocol=ssh;tag=95c570f683c13ce14d2179281b6c81b0f8d245ca;nobranch=1"

