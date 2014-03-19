require alsa-utils.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/alsa-utils;protocol=ssh;tag=4d93f30d1bc8cbe82db962376e71e250507c3b61;nobranch=1"

