require gst-common.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/gst-common;protocol=ssh;tag=4c9bfc97fbfcdd17eb2dc3fa2138df35af0da49a;nobranch=1"

