require corewatcher.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/corewatcher;protocol=ssh;tag=7b5cb6213ea862ee21134ce712596493ca7eb2ba;nobranch=1"

