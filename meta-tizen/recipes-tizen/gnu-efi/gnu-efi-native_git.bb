require gnu-efi.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/gnu-efi;protocol=ssh;tag=f6c0f11ff9d9c2427b94c78a37cc9f7dc47de138;nobranch=1"

