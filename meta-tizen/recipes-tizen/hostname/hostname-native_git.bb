require hostname.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/hostname;protocol=ssh;tag=f9639fe7b32dddb132ae57f460239ca49cc1cc71;nobranch=1"

