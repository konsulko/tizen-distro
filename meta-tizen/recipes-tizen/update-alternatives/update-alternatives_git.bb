require update-alternatives.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/update-alternatives;protocol=ssh;tag=444857fd1227f76e0b3f87a7870694054a426220;nobranch=1"

