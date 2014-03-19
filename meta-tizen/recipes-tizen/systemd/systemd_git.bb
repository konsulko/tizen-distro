require systemd.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/systemd;protocol=ssh;tag=93675e1961f47d1bbe4beb9043cdc3f60ecfc795;nobranch=1"

