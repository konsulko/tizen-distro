require system-plugin-ia-generic.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/adaptation/system-plugin-ia-generic;protocol=ssh;tag=15bb2dcdf4b1de4de103eb79fecec884b1359dcc;nobranch=1"

