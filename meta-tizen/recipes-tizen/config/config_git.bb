require config.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/generic/model/config;protocol=ssh;tag=75e684c6faa9fc986415c6b76993c75d433501fb;nobranch=1"

