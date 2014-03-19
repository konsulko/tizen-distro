require valgrind.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/valgrind;protocol=ssh;tag=8736ad8d45f3459c3d0ec6e75c0aefbfcaa005d6;nobranch=1"

