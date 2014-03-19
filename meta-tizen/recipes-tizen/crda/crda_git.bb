require crda.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/crda;protocol=ssh;tag=60deedc8824dec51c932883929e753b29d057a24;nobranch=1"

