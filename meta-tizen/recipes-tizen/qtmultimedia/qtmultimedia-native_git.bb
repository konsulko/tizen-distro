require qtmultimedia.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/qtmultimedia;protocol=ssh;tag=ab04031896c7f0de245b3da2f674de0291912e45;nobranch=1"

