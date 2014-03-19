require system-installer.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/system-installer;protocol=ssh;tag=1f44f9188240aaa03223ddb8553a9352aa949521;nobranch=1"

