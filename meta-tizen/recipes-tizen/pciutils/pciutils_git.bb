require pciutils.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/pciutils;protocol=ssh;tag=8a698d2538d424760dfbeba1341ef0748d98e9b3;nobranch=1"

