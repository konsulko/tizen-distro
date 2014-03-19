require python-ecore.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/python-ecore;protocol=ssh;tag=c2d6af84ec0c25e33d2ab080a3482dda9b0c8508;nobranch=1"

