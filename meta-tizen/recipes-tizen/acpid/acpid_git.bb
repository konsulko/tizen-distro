require acpid.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/acpid;protocol=ssh;tag=f80becc6f62d4d273077367ae6ee89cf98758853;nobranch=1"

