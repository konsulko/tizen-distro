require pygobject2.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/pygobject2;protocol=ssh;tag=ab8bccfcb4b6be6d38390d730780d82c56c77308;nobranch=1"

