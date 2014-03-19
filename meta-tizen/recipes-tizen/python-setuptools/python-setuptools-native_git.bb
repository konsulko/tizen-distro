require python-setuptools.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/python-setuptools;protocol=ssh;tag=556fe37505b60a30d7e053d95d8a9aeb789a7b30;nobranch=1"

