require imake.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/imake;protocol=ssh;tag=bfd0f368cc71b494078511644b838596eb00b5a2;nobranch=1"

