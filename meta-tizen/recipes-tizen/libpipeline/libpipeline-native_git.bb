require libpipeline.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libpipeline;protocol=ssh;tag=e3bb4a19acf98389748ea0e8486ed4b080064657;nobranch=1"

