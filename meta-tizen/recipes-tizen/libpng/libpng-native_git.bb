require libpng.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libpng;protocol=ssh;tag=67c3a1f00ba76d6c679ca96e96398f8c88bd26fd;nobranch=1"

