require rfkill.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/rfkill;protocol=ssh;tag=8fdd6c46986b07bc8c354f7f8e0af8b233eb4055;nobranch=1"

