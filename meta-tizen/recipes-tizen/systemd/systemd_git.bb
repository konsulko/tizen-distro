require systemd.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/systemd;tag=9d65b1f0d7a6d88e3255b8bb47688ea6a8408927;nobranch=1"

BBCLASSEXTEND += " native "

