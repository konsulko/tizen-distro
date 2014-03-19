require intltool.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/intltool;protocol=ssh;tag=97ec869cac06ac7c217e9f012d175dc624ab5e3f;nobranch=1"

