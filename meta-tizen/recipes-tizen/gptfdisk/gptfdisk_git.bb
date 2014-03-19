require gptfdisk.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/gptfdisk;protocol=ssh;tag=6f943e483ea9e6b4d6fb495de1048aae3840765d;nobranch=1"

