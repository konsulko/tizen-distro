require haptic-module-tizen.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/system/haptic-module-tizen;protocol=ssh;tag=e17885f65fdc41573e6755f442e3a5a951040627;nobranch=1"

