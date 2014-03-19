require xf86vidmodeproto.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/xf86vidmodeproto;protocol=ssh;tag=c6dc4413b970599246b9a2fe963ae35a7c454d27;nobranch=1"

