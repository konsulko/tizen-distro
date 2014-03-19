require json-glib.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/json-glib;protocol=ssh;tag=da80e8a48ecd0ab5580b895a29dff889b87090a8;nobranch=1"

