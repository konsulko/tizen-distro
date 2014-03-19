require fribidi.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/fribidi;protocol=ssh;tag=d96da0b6aa6593b118b22d59a242c4feb5ff4927;nobranch=1"

